/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class edu_cmu_cs_ark_ad3_AD3Jni */

#ifndef _Included_edu_cmu_cs_ark_ad3_AD3Jni
#define _Included_edu_cmu_cs_ark_ad3_AD3Jni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable
  (JNIEnv *, jclass);

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_GetLogPotential
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1GetLogPotential
  (JNIEnv *, jclass, jlong);

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_SetLogPotential
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1SetLogPotential
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_GetId
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1GetId
  (JNIEnv *, jclass, jlong);

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_Degree
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1Degree
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif