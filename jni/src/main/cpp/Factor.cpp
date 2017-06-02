#include "edu_cmu_cs_ark_ad3_AD3Jni.h"
#include "Factor.h"
#include "Utils.h"

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_GetAdditionalLogPotentials
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1GetAdditionalLogPotentials
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    std::vector<double> c_additional_log_potentials = f->GetAdditionalLogPotentials();
    return Utils::convertToJDoubleArray(env, c_additional_log_potentials);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_SetAdditionalLogPotentials
 * Signature: (J[D)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1SetAdditionalLogPotentials
  (JNIEnv *env, jclass cls, jlong handle, jdoubleArray j_additional_log_potentials) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    std::vector<double> c_additional_log_potentials = Utils::convertToDoubleVector(env, j_additional_log_potentials);
    f->SetAdditionalLogPotentials(c_additional_log_potentials);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_Degree
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1Degree
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    return f->Degree();
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_GetLinkId
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1GetLinkId
  (JNIEnv *env, jclass cls, jlong handle, jint i) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    return f->GetLinkId(i);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_GetVariable
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1GetVariable
  (JNIEnv *env, jclass cls, jlong handle, jint i) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    AD3::BinaryVariable *bvPtr = f->GetVariable(i);
    return reinterpret_cast<jlong>(bvPtr);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    Factor_SolveMAP
 * Signature: (J[D[D)Ledu/cmu/cs/ark/ad3/MAPResult;
 */
JNIEXPORT jobject JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_Factor_1SolveMAP
  (JNIEnv *env, jclass cls, jlong handle, jdoubleArray log_potentials, jdoubleArray additional_log_potentials) {
    AD3::Factor *f = reinterpret_cast<AD3::Factor *>(handle);
    std::vector<double> variable_posteriors;
    std::vector<double> additional_posteriors;
    double value;

    std::vector<double> c_log_potentials = Utils::convertToDoubleVector(env, log_potentials);
    std::vector<double> c_additional_log_potentials = Utils::convertToDoubleVector(env, additional_log_potentials);
    f->SolveMAP(c_log_potentials, c_additional_log_potentials, &variable_posteriors, &additional_posteriors, &value);

    return Utils::createMAPResult(env, variable_posteriors, additional_posteriors, value);
  }