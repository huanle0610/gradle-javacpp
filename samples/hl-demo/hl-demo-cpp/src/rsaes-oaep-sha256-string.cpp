#include <cryptopp/filters.h>
#include <iostream>
#include <cstdlib>
#include "cryptopp/cryptlib.h"
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/files.h"
#include "cryptopp/base64.h"
#include <cryptopp/pem.h>
#include "assert.h"
#include <windows.h>

using std::ifstream;
using std::ostringstream;

std::string readFileIntoString(const std::string &path)
{
    ifstream input_file(path, std::ios_base::binary);
    if (!input_file.is_open())
    {
        std::cerr << "Could not open the file - '"
                  << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    input_file.seekg(0, std::ios_base::end);
    size_t length = input_file.tellg();
    input_file.seekg(0, std::ios_base::beg);
    std::string res = std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    assert(length == res.length());
    return res;
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(65001);
    using namespace CryptoPP;

    // 建立隨機亂數產生器
    AutoSeededRandomPool prng;

    // 原始資料、加密資料、解密後資料
    std::string plain = "The quick brown fox jumps over the lazy dog", cipher, recovered;

    std::cout << "原始資料：" << plain << std::endl;

    try
    {
        // 從檔案載入 RSA 公鑰
        RSA::PublicKey rsaPubKey, pk2;
        FileSource pubKeyFile("hl-bin.pub", true);
        rsaPubKey.Load(pubKeyFile);

        std::vector<byte> spki;
        std::ifstream inFile("hl-bin.pub", std::ios_base::binary);
        inFile.seekg(0, std::ios_base::end);
        size_t length = inFile.tellg();
        inFile.seekg(0, std::ios_base::beg);
        // spki.resize(length);
        std::copy(std::istreambuf_iterator<char>(inFile),
                  std::istreambuf_iterator<char>(),
                  std::back_inserter(spki));
        assert(spki.size() == length);

        ArraySource as2(&spki[0], spki.size(), true);
        pk2.Load(as2);

        // 以 RSA 公鑰建立 RSAES 加密器（採用 SHA256）
        // RSAES<OAEP<SHA256>>::Encryptor encryptor(rsaPubKey);
        RSAES<OAEP<SHA256>>::Encryptor encryptor(pk2);

        // 確認明文長度沒有超過上限值
        assert(plain.size() <= encryptor.FixedMaxPlaintextLength());

        // 以 RSAES 加密
        StringSource ss1(plain, true,
                         new PK_EncryptorFilter(prng, encryptor,
                                                new StringSink(cipher)) // PK_EncryptorFilter
        );                                                              // StringSource

        // 從檔案載入 RSA 私鑰
        RSA::PrivateKey rsaPrivKey;
        FileSource privKeyFile("hl-bin.key", true);
        rsaPrivKey.Load(privKeyFile);

        // 以 RSA 私鑰建立 RSAES 解密器（採用 SHA256）
        RSAES<OAEP<SHA256>>::Decryptor decryptor(rsaPrivKey);

        // 以 RSAES 解密
        StringSource ss2(cipher, true,
                         new PK_DecryptorFilter(prng, decryptor,
                                                new StringSink(recovered)) // PK_DecryptorFilter
        );                                                                 // StringSource
        assert(recovered == plain);
        recovered = "";
        assert(recovered != plain);

        // 以 RSAES 解密 from file
        std::string enMsg = readFileIntoString("en_msg.bin");
        StringSource ss3(enMsg, true,
                         new PK_DecryptorFilter(prng, decryptor,
                                                new StringSink(recovered)) // PK_DecryptorFilter
        );                                                                 // StringSource
        assert(recovered == plain);

        std::cout << "解密資料：" << recovered << std::endl;
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}