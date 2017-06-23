package edu.cmu.cs.ark.ad3;

class AD3CObjType {
    static final int NATIVE = 0;
    static final int MANAGED = 1;
}

class AD3CObj {
    private long cptr = 0L;
    private int type = -1;

    AD3CObj(long paramLong, int paramInt) {
        this.cptr = paramLong;
        this.type = paramInt;
    }

    long get() {
        return this.cptr;
    }

    int getType() {
        return this.type;
    }
}
