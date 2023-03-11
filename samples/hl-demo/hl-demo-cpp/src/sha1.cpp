#include <iostream>
#include <cstdlib>
#include "cryptopp/cryptlib.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/sha.h"
#include "cryptopp/hex.h"
int main()
{
    using namespace CryptoPP;
    SHA1 hash;
    std::string msg = "Crypto++ is a free C++ library for cryptography.";
    std::string digest;
    HexEncoder encoder(new FileSink(std::cout));

    hash.Update((const byte *)msg.data(), msg.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte *)digest.c_str());

    std::cout << "Message: " << msg << std::endl;
    std::cout << "SHA1 Digest: ";
    StringSource(digest, true, new Redirector(encoder));
    std::cout << std::endl;

    return EXIT_SUCCESS;
}