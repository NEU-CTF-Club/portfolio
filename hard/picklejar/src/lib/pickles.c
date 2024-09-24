#include "Main.h"
#include "jni.h"
#include "stdio.h"
#include <string.h>

int consideration(const char *encoded) {
  if (strlen(encoded) != 20) {
    return 0;
  }

  if (encoded[10] + 2 == 0x75 && encoded[13] + 58 == 0xa2 &&
      encoded[8] + 72 == 0xb4 && encoded[5] + 71 == 0x78 &&
      encoded[1] + 86 == 0xaa && encoded[4] + 51 == 0xa3 &&
      encoded[3] + 55 == 0xb2 && encoded[17] + 8 == 0x3c &&
      encoded[2] + 41 == 0x6f && encoded[14] + 50 == 0x65 &&
      encoded[12] + 40 == 0x9c && encoded[19] + 86 == 0xd3 &&
      encoded[7] + 1 == 0x6c && encoded[16] + 86 == 0xb9 &&
      encoded[6] + 54 == 0x99 && encoded[11] + 80 == 0xaf &&
      encoded[18] + 67 == 0xb7 && encoded[15] + 34 == 0x81 &&
      encoded[9] + 73 == 0x7c && encoded[0] + 84 == 0x97) {
    return 1;
  }

  return 0;
}

JNIEXPORT jboolean JNICALL Java_Main_checkFlag(JNIEnv *env, jclass thisClass,
                                               jstring flag) {
  const char *flagStr = (*env)->GetStringUTFChars(env, flag, 0);

  int retVal = consideration(flagStr);

  (*env)->ReleaseStringUTFChars(env, flag, flagStr);

  return retVal;
}
