package edu.cmu.cs.ark.ad3;

public final class Factor {
    private AD3CObj nativeObj = null;

    Factor(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, AD3CObjType.NATIVE);
    }

    public double[] getAdditionalLogPotentials() {
        return AD3Jni.Factor_GetAdditionalLogPotentials(this.nativeObj.get());
    }

    public void setAdditionalLogPotentials(double[] additionalLogPotentials) {
        AD3Jni.Factor_SetAdditionalLogPotentials(this.nativeObj.get(), additionalLogPotentials);
    }

    public int getDegree() {
        return AD3Jni.Factor_Degree(this.nativeObj.get());
    }

    public int getLinkId(int i) {
        return AD3Jni.Factor_GetLinkId(this.nativeObj.get(), i);
    }

    public BinaryVariable getVariable(int i) {
        long bvPtr = AD3Jni.Factor_GetVariable(this.nativeObj.get(), i);
        return new BinaryVariable(bvPtr);
    }

    public MAPResult solveMAP(double[] variableLogPotentials, double[] additionalLogPotentials) {
        return AD3Jni.Factor_SolveMAP(this.nativeObj.get(), variableLogPotentials, additionalLogPotentials);
    }

    public long getNativeHandle() {
        return this.nativeObj.get();
    }
}
