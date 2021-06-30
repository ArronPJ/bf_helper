#include <iostream>
#include "bf_helper.h"

static const int32_t k_bf_helper_version_major = 1;
static const int32_t k_bf_helper_version_minor = 2;
static const int32_t k_bf_helper_version_patch = 1;
// V1.0.0 : create this library
// V1.1.0 : provide version function
// V1.2.0 : add decoder init and shutdown into single source code.

//Gloabal flag

/// PART "bf_decoder"

static bool g_avcodec_registed = false;

/// PART "bf_decoder" END

void bf_helper_version()
{
    char version[64];
    sprintf(version, "version=%d.%d.%d",
            k_bf_helper_version_major,
            k_bf_helper_version_minor,
            k_bf_helper_version_patch);
#ifdef NDEBUG
    std::cout
        << "bf_helper: " << version << " Release!" << std::endl;
#else
    std::cout
        << "bf_helper: " << version << " Debug!" << std::endl;
#endif
}

//void bf_helper_init(){}
//void bf_helper_shutdown(){}

/// ============= "bf_decoder" START ===========
bool bf_decoder_init()
{
    if (!g_avcodec_registed)
    {
        //FFMPEG Register_all
        g_avcodec_registed = true;
    }
    //get version from ffmpeg
    return true;
}
void bf_decoder_shutdown()
{
}
/// ============= "bf_decoder" END =============