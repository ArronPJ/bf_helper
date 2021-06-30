#include "bf_helper.h"
#include "bf_object.h"

#include <stdio.h> //for printf

void check_library_version()
{
    bf_helper_version();
    const char *ov = bf_object_version();
    printf("check version, %s\n", ov);
}

void run_decoder_process()
{
    bf_decoder_init();
    bf_decoder_shutdown();
}

int main()
{
    check_library_version();
    run_decoder_process();
}
