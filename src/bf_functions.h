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

#ifdef _WINDOWS
    typedef signed char int8_t;
    typedef signed short int16_t;
    typedef signed int int32_t;
    typedef unsigned char uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int uint32_t;
    typedef signed long long int64_t;
    typedef unsigned long long uint64_t;
#else
#include <inttypes.h>
#endif
    //////////////////////////////////////////
    struct bf_target_object; //target object

    typedef struct bf_object_config_packet
    {
        char hostname[64];   /*utility ip address */
        int32_t serviceport; /*utility listen port*/
        char username[32];   /*login username*/
        char passwd[32];     /*login password*/
        int32_t object_type;

        char Reserve1[32];
        char Reserve2[32];
        bf_object_config_packet()
        {
            object_type = 0;
        }
    } bf_object_config_packet;

    typedef struct geo_onvif_search_params
    {
        bf_object_config_packet config_packet; //
        //geo_onvif_discovery_params      discovery_params;   //host callback information.
    } bf_create_object_config_params;
    //////////////////////////////////////////
    bf_helper_EXPORT bool bf_functions_init();
    bf_helper_EXPORT void bf_functions_shutdown();

    bf_helper_EXPORT bool bf_create_object(const bf_create_object_config_params *params, bf_target_object **target_object);
    bf_helper_EXPORT void bf_release_object(bf_target_object **target_object);

// == CPP ======================(FOOTER-START)
#ifdef __cplusplus
}
#endif
/// == CPP ======================(FOOTER-END)
