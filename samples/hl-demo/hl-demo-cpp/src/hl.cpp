#include "hl.h"

void bc()
{
    std::cout << "hl" << std::endl;
}

int getPublicKeySize()
{

    uint8_t pubKey[] = PUBLIC_KEY;
    int i = 0;
    for (; i < PUBLIC_KEY_LEN; i++)
    {
        // std::cout << pubKey[i] << std::endl;
    }
    std::cout << "getPublicKeySize " << (int)pubKey[i - 1] << std::endl;

    return i;
}

int acquire_license()
{
    LicenseInfo licenseInfo;
    size_t pc_id_sz = LCC_API_PC_IDENTIFIER_SIZE + 1;
    char pc_identifier[LCC_API_PC_IDENTIFIER_SIZE + 1];

    LCC_EVENT_TYPE result = acquire_license(nullptr, nullptr, &licenseInfo);
    return 3;
    // return LICENSE_FILE_NOT_FOUND;
}

LCC_EVENT_TYPE acquire_license(const CallerInformations *callerInformation, const LicenseLocation *licenseLocation,
                               LicenseInfo *license_out)
{
    return LICENSE_FILE_NOT_FOUND;
}