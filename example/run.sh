#!/bin/bash
set -ex



#rm ./*.so ./*.o

CFLAGS="-fPIC -c"
LDFLAGS="-shared "
LIBS="-ldl -lrt"

rm -rf ./lib1
rm -rf ./lib2

#Crypto v1
gcc ${CFLAGS} -o crypto_v1.o crypto_v1.c
gcc ${LDFLAGS} -o libcrypto_v1.so crypto_v1.o ${LIBS}


#Crypto v1
gcc ${CFLAGS} -o crypto_v2.o crypto_v2.c
gcc ${LDFLAGS} -o libcrypto_v2.so crypto_v2.o ${LIBS}


#JNI v1
gcc ${CFLAGS} -o jni_v1.o jni_v1.c 
gcc ${LDFLAGS} -o jni_v1.so jni_v1.o ${LIBS} -L./ -lcrypto_v1 -Wl,-rpath,'$ORIGIN' 


#JNI v2
gcc ${CFLAGS} -o jni_v2.o jni_v2.c 
gcc ${LDFLAGS} -o jni_v2.so jni_v2.o ${LIBS} -L./ -lcrypto_v2 -Wl,-rpath,'$ORIGIN'

rm ./*.o

mkdir -p lib1
mv libcrypto_v1.so ./lib1
mv jni_v1.so ./lib1

mkdir -p lib2
mv libcrypto_v2.so ./lib2
mv jni_v2.so ./lib2

gcc -o java java.c ${LIBS}

./java