#include <iostream>
#include <cstdlib>
#include "cryptopp/cryptlib.h"
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/files.h"
#include "assert.h"
#include <windows.h>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(65001);
    using namespace CryptoPP;

    // 建立隨機亂數產生器
    AutoSeededRandomPool prng;

    // 原始資料、加密資料、解密後資料
    std::string plain = "RSA Encryption", cipher, recovered;

    std::cout << "原始資料：" << plain << std::endl;

    try
    {
        // 從檔案載入 RSA 公鑰
        RSA::PublicKey rsaPubKey;
        FileSource pubKeyFile("rsa_pub.key", true);
        rsaPubKey.Load(pubKeyFile);

        // 以 RSA 公鑰建立 RSAES 加密器（採用 SHA256）
        RSAES<OAEP<SHA256>>::Encryptor encryptor(rsaPubKey);

        // 確認明文長度沒有超過上限值
        assert(plain.size() <= encryptor.FixedMaxPlaintextLength());

        // 以 RSAES 加密
        StringSource ss1(plain, true,
                         new PK_EncryptorFilter(prng, encryptor,
                                                new StringSink(cipher)) // PK_EncryptorFilter
        );                                                              // StringSource

        // 從檔案載入 RSA 私鑰
        RSA::PrivateKey rsaPrivKey;
        FileSource privKeyFile("rsa_priv.key", true);
        rsaPrivKey.Load(privKeyFile);

        // 以 RSA 私鑰建立 RSAES 解密器（採用 SHA256）
        RSAES<OAEP<SHA256>>::Decryptor decryptor(rsaPrivKey);

        // 以 RSAES 解密
        StringSource ss2(cipher, true,
                         new PK_DecryptorFilter(prng, decryptor,
                                                new StringSink(recovered)) // PK_DecryptorFilter
        );                                                                 // StringSource

        std::cout << "解密資料：" << recovered << std::endl;
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}