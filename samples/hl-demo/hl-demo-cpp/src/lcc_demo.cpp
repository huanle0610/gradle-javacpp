
#include "datatypes.h"
#include <iostream>
#include <licensecc.h>

int main(int argc, char const *argv[])
{

    LicenseInfo licenseInfo;
    size_t pc_id_sz = LCC_API_PC_IDENTIFIER_SIZE + 1;
    char pc_identifier[LCC_API_PC_IDENTIFIER_SIZE + 1];

    LCC_EVENT_TYPE result = acquire_license(nullptr, nullptr, &licenseInfo);
    if (identify_pc(STRATEGY_DEFAULT, pc_identifier, &pc_id_sz, nullptr))
    {
        std::cout << "pc signature is :" << std::endl;
        std::cout << "    " << pc_identifier << std::endl;
    }
    else
    {
        std::cerr << "errors in identify_pc" << std::endl;
    }

    std::cout << "hl" << std::endl;
    std::cout << result << std::endl;
    LicenseLocation licLocation;
    licLocation.license_data_type = LICENSE_PATH;
    strcpy(licLocation.licenseData, "Brutalizer");
    char *feat = "abc";
    confirm_license(feat, &licLocation);
    release_license(feat, &licLocation);
    return 0;
}
