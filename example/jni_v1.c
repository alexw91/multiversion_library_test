#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "crypto.h"

void* dlopen_helper(char const *path) {
    void *result = dlopen(path, RTLD_LAZY | RTLD_LOCAL);

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

//static int callback(struct dl_phdr_info *info, size_t size, void *data)
//{
//    int j;
//
//   printf("name=%s (%d segments)\n", info->dlpi_name, info->dlpi_phnum);
//
//   for (j = 0; j < info->dlpi_phnum; j++){
//         printf("\t\t header %2d: address=%10p\n", j, (void *) (info->dlpi_addr + info->dlpi_phdr[j].p_vaddr));
//   }
//    return 0;
//}


int call_jni_v1(void)
{
    printf("Entered call_jni_v1()...\n");
//    dl_iterate_phdr(callback, NULL);
//    dlopen_helper("./libcrypto_v1.so");
    call_crypto();
    return 0;
}
