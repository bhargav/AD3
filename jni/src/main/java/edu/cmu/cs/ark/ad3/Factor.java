package edu.cmu.cs.ark.ad3;

public final class Factor {
    private AD3CObj nativeObj = null;

    Factor(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, AD3CObjType.NATIVE);
    }

    public double[] GetAdditionalLogPotentials() {
        return AD3Jni.Factor_GetAdditionalLogPotentials(this.nativeObj.get());
    }

    public void SetAdditionalLogPotentials(double[] additionalLogPotentials) {
        AD3Jni.Factor_SetAdditionalLogPotentials(this.nativeObj.get(), additionalLogPotentials);
    }

    public int Degree() {
        return AD3Jni.Factor_Degree(this.nativeObj.get());
    }

    public int GetLinkId(int i) {
        return AD3Jni.Factor_GetLinkId(this.nativeObj.get(), i);
    }

    public BinaryVariable GetVariable(int i) {
        long bvPtr = AD3Jni.Factor_GetVariable(this.nativeObj.get(), i);
        return new BinaryVariable(bvPtr);
    }

    public MAPResult SolveMAP(double[] variableLogPotentials, double[] additionalLogPotentials) {
        return AD3Jni.Factor_SolveMAP(this.nativeObj.get(), variableLogPotentials, additionalLogPotentials);
    }

    public long getNativeHandle() {
        return this.nativeObj.get();
    }
}
