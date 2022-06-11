#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "crypto.h"

void* dlopen_helper(char const *path) {
    void *result = dlopen(path, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);

    if(dlopen_helper == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    } else {
        printf("successfully loaded %s!\n", path);
    }

    return result;
}

void * dlsym_helper(void *handle, char const *symbol){
    char *error = dlerror();
    if (error != NULL) {
        printf("Found abandoned dlerror: %s\n", error);
    }

    void *result = dlsym(handle, symbol);

    error = dlerror();

    if (error != NULL) {
        printf("Error finding symbol: %s. Error: %s\n", symbol, error);
    }
    return result;
}

int call_jni_v2(void)
{
    printf("Entered call_jni_v2()...\n");

    dlopen_helper("./libcrypto_v2.so");

    call_crypto();
    return 0;
}
