#!/bin/bash
set -ex



#rm ./*.so ./*.o

CFLAGS="-fPIC -c"
LDFLAGS="-shared "
LIBS="-ldl -lrt"


#Crypto v1
gcc ${CFLAGS} -o crypto_v1.o crypto_v1.c
gcc ${LDFLAGS} -o libcrypto_v1.so crypto_v1.o ${LIBS}


#Crypto v1
gcc ${CFLAGS} -o crypto_v2.o crypto_v2.c
gcc ${LDFLAGS} -o libcrypto_v2.so crypto_v2.o ${LIBS}


#JNI v1
gcc ${CFLAGS} -o jni_v1.o jni_v1.c 
gcc ${LDFLAGS} -o jni_v1.so jni_v1.o ${LIBS} #-L./ -lcrypto_v1


#JNI v2
gcc ${CFLAGS} -o jni_v2.o jni_v2.c 
gcc ${LDFLAGS} -o jni_v2.so jni_v2.o ${LIBS} #-L./ -lcrypto_v2


gcc -o java java.c ${LIBS}

./java