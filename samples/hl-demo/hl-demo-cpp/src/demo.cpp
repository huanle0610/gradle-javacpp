
#include "hl.h"

int main(int argc, char const *argv[])
{

    LicenseInfo licenseInfo;
    size_t pc_id_sz = LCC_API_PC_IDENTIFIER_SIZE + 1;
    char pc_identifier[LCC_API_PC_IDENTIFIER_SIZE + 1];

    LCC_EVENT_TYPE result1 = acquire_license(nullptr, nullptr, &licenseInfo);
    int result = acquire_license();

    std::cout << "hl" << std::endl;
    std::cout << getPublicKeySize() << std::endl;
    std::cout << result << std::endl;
    std::cout << result1 << std::endl;
    return 0;
}
