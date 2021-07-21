#include "bf_helper.h"
#include "bf_object.h"
#include "bf_functions.h"

#include <stdio.h>  //for printf
#include <string.h> //memset
#include <iostream> //nullptr

//#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
//#include <catch2/catch.hpp>
//#include "catch.hpp"

void check_library_version()
{
    bf_helper_version();
    const char *ov = bf_object_version();
    printf("check sub, %s\n", ov);
}

void check_object_usage()
{
    bf_object *o1 = bf_object_create();
    bf_object_release(&o1);
    printf("check object_pointer = %x\n", o1);
    //add usage sample code for bf_object
}
void check_function_target_creation()
{
    bf_create_object_config_params params;
    memset(&params, 0, sizeof(bf_create_object_config_params));

    bf_target_object *object_ref = nullptr;

    bool result = bf_create_object(&params, &object_ref);
    if (result == true)
    {
        printf("check create ok\n");
    }
    else
    {
        printf("check create fail\n");
    }
    bf_release_object(&object_ref);
}

void run_decoder_process()
{
    bf_decoder_init();
    bf_decoder_shutdown();
}

int main()
{
    //01
    check_library_version();
    //02
    check_object_usage();
    //03
    check_function_target_creation();
    //04
    run_decoder_process();
}

// unsigned int Factorial(unsigned int number)
// {
//     return number <= 1 ? number : Factorial(number - 1) * number;
// }

// TEST_CASE("Factorials are computed", "[factorial]")
// {
//     REQUIRE(Factorial(1) == 1);
//     REQUIRE(Factorial(2) == 2);
//     REQUIRE(Factorial(3) == 6);
//     REQUIRE(Factorial(10) == 3628800);
// }
