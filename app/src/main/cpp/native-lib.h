//
// Created by ЕлисеевРВ on 17.07.2019.
//

#ifndef FIRSTNATIVECAPP_NATIVE_LIB_H
#define FIRSTNATIVECAPP_NATIVE_LIB_H


std::string jstring2string(JNIEnv *env, jstring jStr);
jbyteArray getByteArray(JNIEnv *env, jstring jStr);

#endif //FIRSTNATIVECAPP_NATIVE_LIB_H
