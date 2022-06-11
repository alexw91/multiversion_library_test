#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "crypto.h"



int call_jni_v1(void)
{
    printf("Entered call_jni_v1()...\n");
    call_crypto();
    return 0;
}
