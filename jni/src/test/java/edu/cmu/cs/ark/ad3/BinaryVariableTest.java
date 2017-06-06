package edu.cmu.cs.ark.ad3;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BinaryVariableTest {
    @Test
    public void testCreateNewInstance() {
        BinaryVariable variable = new BinaryVariable();
        variable.setLogPotential(0.3);
        assertEquals(variable.getLogPotential(), 0.3, 0.01);
    }
}
