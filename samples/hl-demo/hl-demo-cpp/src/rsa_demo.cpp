#include <iostream>
#include <cstdlib>
#include "cryptopp/cryptlib.h"
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/files.h"

int main(int argc, char *argv[])
{
    using namespace CryptoPP;

    // 建立隨機亂數產生器
    AutoSeededRandomPool prng;

    try
    {
        // 產生 RSA 私鑰
        RSA::PrivateKey rsaPrivKey;
        rsaPrivKey.GenerateRandomWithKeySize(prng, 3072);

        // 產生對應的 RSA 公鑰
        RSA::PublicKey rsaPubKey(rsaPrivKey);

        // 儲存 RSA 私鑰
        FileSink privKeyFile("rsa_priv.key");
        rsaPrivKey.Save(privKeyFile);

        // 儲存 RSA 公鑰
        FileSink pubKeyFile("rsa_pub.key");
        rsaPubKey.Save(pubKeyFile);
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        // 從檔案載入 RSA 金鑰
        RSA::PrivateKey rsaPrivKey2;
        FileSource privKeyFile2("rsa_priv.key", true);
        rsaPrivKey2.Load(privKeyFile2);

        // 驗證 RSA 私鑰
        if (!rsaPrivKey2.Validate(prng, 3))
        {
            std::cerr << "RSA 私鑰驗證失敗" << std::endl;
            return EXIT_FAILURE;
        }

        // 產生對應的 RSA 公鑰
        RSA::PublicKey rsaPubKey2(rsaPrivKey2);
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}