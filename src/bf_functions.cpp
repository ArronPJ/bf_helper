
#include "bf_functions.h"

#include <stdio.h>
//C++
#include <iostream>

#ifdef __WIN32_OS__
#include "unistd_win32.h"
#elif (__APPLE_OS__ || IOS || __LINUX_OS__ || __VXWORKS_OS__)
#include <unistd.h>
#endif

//boost related
#include "boost/function.hpp"
#include "boost/asio.hpp"
#include "boost/thread.hpp"

//////////////////////////////////////////
// Structure

typedef struct bf_target_object
{
    bf_object_config_packet init_info; //HOST_SEARCH_INIT
    int32_t target_index;
    //onvif_device_manager *onvif_search_object;

public:
    bf_target_object() : target_index(0) /*, bf_target_object(nullptr)*/ {}

} bf_target_object;
void get_boost_version()
{
    char b_version[64];
    sprintf(b_version, "%d.%d.%d",
            (BOOST_VERSION / 100000),
            (BOOST_VERSION / 100 % 1000),
            (BOOST_VERSION % 100));
    std::cout
        << "boost_version: " << b_version << std::endl;
}
bool bf_functions_init()
{

    return false;
}

void bf_functions_shutdown()
{
}
//
bool bf_create_object(const bf_create_object_config_params *params, bf_target_object **target_object)
{
    get_boost_version();
    if (!params)
    {
        return false;
    }
    bf_target_object *object = new bf_target_object;

    *target_object = object;
    return true;
}
//
void bf_release_object(bf_target_object **target_object)
{
    if (*target_object)
    {
        // if ((*target_object)->onvif_search_object->is_searching() == true)
        // {
        //     (*target_object)->onvif_search_object->search_stop();
        // }
    }

    delete *target_object;
    *target_object = nullptr;
}
