#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "crypto.h"

int call_jni_v2(void)
{
    printf("Entered call_jni_v2()...\n");

    call_crypto();
    return 0;
}
