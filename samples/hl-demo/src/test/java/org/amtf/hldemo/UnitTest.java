package org.amtf.hldemo;

import org.bytedeco.javacpp.IntPointer;
import org.junit.Test;

import java.util.Arrays;

import static org.amtf.hldemo.global.hldemo.*;
import static org.junit.Assert.assertEquals;

public class UnitTest {
    @Test public void test() {
//        System.out.println(zlibVersion().getString());
//        assertEquals("1.2.13", zlibVersion().getString());
//        assertEquals(140, getPublicKeySize());
        int len = 55;
        byte[] s = new byte[len];
        IntPointer it = new IntPointer(1);
        it.put(len);
        identify_pc(LCC_API_HW_IDENTIFICATION_STRATEGY.STRATEGY_DEFAULT, s, it, null);
        assertEquals("AAA0-4S1o-71c=", new String(s).trim());
    }
}

