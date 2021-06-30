#include "bf_helper.h"
#include "bf_object.h"

#include <stdio.h> //for printf

void check_library_version()
{
    bf_helper_version();
    const char *ov = bf_object_version();
    printf("check version, %s\n", ov);
}

void check_object_usage()
{
    bf_object *o1 = bf_object_create();
    bf_object_release(&o1);
    printf("check pointer = %x\n", o1);
}

void run_decoder_process()
{
    bf_decoder_init();
    bf_decoder_shutdown();
}

int main()
{
    check_library_version();
    check_object_usage();
    run_decoder_process();
}
