#pragma once

#ifdef WIN32
#define bf_helper_EXPORT __declspec(dllexport)
#else
#define bf_helper_EXPORT
#endif
// == CPP ======================(HEADER)
#ifdef __cplusplus
extern "C"
{
#endif
/// == CPP ======================(HEADER END)
//C
#include <stdint.h>

    bf_helper_EXPORT void bf_helper_version();

    bf_helper_EXPORT bool bf_decoder_init();
    bf_helper_EXPORT void bf_decoder_shutdown();

// == CPP ======================(FOOTER-START)
#ifdef __cplusplus
}
#endif
/// == CPP ======================(FOOTER-END)