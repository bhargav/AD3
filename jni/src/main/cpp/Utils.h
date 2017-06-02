#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include <jni.h>
#include <vector>

namespace Utils {
    jdoubleArray convertToJDoubleArray(JNIEnv *, std::vector<double>);

    std::vector<double> convertToDoubleVector(JNIEnv *, jdoubleArray);

    std::vector<bool> convertToBoolVector(JNIEnv *, jbooleanArray);

    jobject createMAPResult(JNIEnv *, std::vector<double>, std::vector<double>, double);

    jobject createMAPResultWithStatus(JNIEnv *, std::vector<double>, std::vector<double>, double, int);
}

#endif