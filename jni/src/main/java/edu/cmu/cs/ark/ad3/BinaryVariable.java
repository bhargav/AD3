package edu.cmu.cs.ark.ad3;

public final class BinaryVariable {
    public AD3CObj nativeObj = null;

    private BinaryVariable(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, 1);
    }

    public BinaryVariable() {
        long nativeHandler = AD3Jni.BinaryVariable();
        this.nativeObj = new AD3CObj(nativeHandler, 1);
    }

    public double GetLogPotential() {
        return AD3Jni.BinaryVariable_GetLogPotential(this.nativeObj.get());
    }

    public void SetLogPotential(double logPotential) {
        AD3Jni.BinaryVariable_SetLogPotential(this.nativeObj.get(), logPotential);
    }

    public int GetId() {
        return AD3Jni.BinaryVariable_GetId(this.nativeObj.get());
    }

    public int Degree() {
        return AD3Jni.BinaryVariable_Degree(this.nativeObj.get());
    }
}
