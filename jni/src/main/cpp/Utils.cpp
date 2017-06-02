#include "Utils.h"

namespace Utils {
    jdoubleArray convertToJDoubleArray(JNIEnv *env, std::vector<double> inputVector) {
        jdoubleArray output = env->NewDoubleArray(inputVector.size());
        env->SetDoubleArrayRegion(output, 0, inputVector.size(), &inputVector[0]);
        return output;
    }

    std::vector<double> convertToDoubleVector(JNIEnv *env, jdoubleArray inputArray) {
        jsize size = env->GetArrayLength(inputArray);
        std::vector<double> outputVector(size);
        env->GetDoubleArrayRegion(inputArray, 0, size, &outputVector[0]);
        return outputVector;
    }

    std::vector<bool> convertToBoolVector(JNIEnv *env, jbooleanArray inputArray) {
        jsize size = env->GetArrayLength(inputArray);
        std::vector<bool> outputVector(size);

        jboolean *body = env->GetBooleanArrayElements(inputArray, 0);
        for (int i=0; i<size; i++) {
            outputVector.push_back(body[i]);
        }
        env->ReleaseBooleanArrayElements(inputArray, body, 0);

        return outputVector;
    }

    jobject createMAPResult(JNIEnv *env, std::vector<double> variable_posteriors, std::vector<double> additional_posteriors, double value) {
        jclass jcls = env->FindClass("edu/cmu/cs/ark/ad3/MAPResult");

        jdoubleArray variable_posteriors_jArray = convertToJDoubleArray(env, variable_posteriors);
        jdoubleArray additional_posteriors_jArray = convertToJDoubleArray(env, additional_posteriors);

        jmethodID mID = env->GetMethodID(jcls, "<init>", "([D[DD)V");

        jobject jobj = env->NewObject(jcls, mID, variable_posteriors_jArray, additional_posteriors_jArray, value);
        return jobj;
    }

    jobject createMAPResultWithStatus(JNIEnv *env, std::vector<double> variable_posteriors, std::vector<double> additional_posteriors, double value, int status) {
        jclass jcls = env->FindClass("edu/cmu/cs/ark/ad3/MAPResult");

        jdoubleArray variable_posteriors_jArray = convertToJDoubleArray(env, variable_posteriors);
        jdoubleArray additional_posteriors_jArray = convertToJDoubleArray(env, additional_posteriors);

        jmethodID mID = env->GetMethodID(jcls, "<init>", "([D[DDI)V");

        jobject jobj = env->NewObject(jcls, mID, variable_posteriors_jArray, additional_posteriors_jArray, value, status);
        return jobj;
    }
}