#include <iostream>
#include "bf_helper.h"

static const int32_t k_bf_helper_version_major = 1;
static const int32_t k_bf_helper_version_minor = 1;
static const int32_t k_bf_helper_version_patch = 0;

void bf_helper_version()
{
    char version[64];
    sprintf(version, "version=%d.%d.%d",
            k_bf_helper_version_major,
            k_bf_helper_version_minor,
            k_bf_helper_version_patch);
#ifdef NDEBUG
    std::cout
        << "bf_helper/1.0: " << version << " Release!" << std::endl;
#else
    std::cout
        << "bf_helper/1.0: " << version << " Debug!" << std::endl;
#endif
}

//void bf_helper_init(){}
//void bf_helper_shutdown(){}