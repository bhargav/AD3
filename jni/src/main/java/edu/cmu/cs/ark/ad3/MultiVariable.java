package edu.cmu.cs.ark.ad3;

public final class MultiVariable {
    private AD3CObj nativeObj = null;

    MultiVariable(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, AD3CObjType.NATIVE);
    }

    public MultiVariable() {
        long nativeHandler = AD3Jni.MultiVariable();
        this.nativeObj = new AD3CObj(nativeHandler, AD3CObjType.MANAGED);
    }

    public int getNumStates() {
        return AD3Jni.MultiVariable_GetNumStates(this.nativeObj.get());
    }

    public BinaryVariable getState(int i) {
        long bvPtr = AD3Jni.MultiVariable_GetState(this.nativeObj.get(), i);
        return new BinaryVariable(bvPtr);
    }

    public double getLogPotential(int i) {
        return AD3Jni.MultiVariable_GetLogPotential(this.nativeObj.get(), i);
    }

    public void setLogPotential(int i, double logPotential) {
        AD3Jni.MultiVariable_SetLogPotential(this.nativeObj.get(), i, logPotential);
    }

    public long getNativeHandle() {
        return this.nativeObj.get();
    }
}
