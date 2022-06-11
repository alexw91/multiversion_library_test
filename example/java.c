#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "crypto.h"

void* dlopen_helper(char const *path) {
    void *result = dlopen(path, RTLD_LAZY);

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

int main(int argc, char **argv)
{
    void *jni_v1_handle = dlopen_helper("./jni_v1.so");
    int (*call_jni_v1)(void);
    call_jni_v1 = dlsym_helper(jni_v1_handle, "call_jni_v1");

    printf("Calling call_jni_v1()...\n");
    call_jni_v1();



    void *jni_v2_handle = dlopen_helper("./jni_v2.so");
    int (*call_jni_v2)(void);
    call_jni_v2 = dlsym_helper(jni_v2_handle, "call_jni_v2");

    printf("Calling call_jni_v2()...\n");
    call_jni_v2();


    return 0;
}
