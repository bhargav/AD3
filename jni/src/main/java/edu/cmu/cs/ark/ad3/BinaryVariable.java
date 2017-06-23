package edu.cmu.cs.ark.ad3;

public final class BinaryVariable {
    private AD3CObj nativeObj = null;

    BinaryVariable(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, AD3CObjType.NATIVE);
    }

    public BinaryVariable() {
        long nativeHandler = AD3Jni.BinaryVariable();
        this.nativeObj = new AD3CObj(nativeHandler, AD3CObjType.MANAGED);
    }

    public double getLogPotential() {
        return AD3Jni.BinaryVariable_GetLogPotential(this.nativeObj.get());
    }

    public void setLogPotential(double logPotential) {
        AD3Jni.BinaryVariable_SetLogPotential(this.nativeObj.get(), logPotential);
    }

    public int getId() {
        return AD3Jni.BinaryVariable_GetId(this.nativeObj.get());
    }

    public int getDegree() {
        return AD3Jni.BinaryVariable_Degree(this.nativeObj.get());
    }

    public long getNativeHandle() {
        return this.nativeObj.get();
    }

    @Override
    protected void finalize() throws Throwable {
        if (this.nativeObj.getType() == AD3CObjType.MANAGED) {
            AD3Jni.BinaryVariable_Dispose(this.nativeObj.get());
        }

        super.finalize();
    }
}
