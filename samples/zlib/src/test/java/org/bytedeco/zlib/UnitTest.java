package org.bytedeco.zlib;

import org.junit.Test;
import static org.bytedeco.zlib.global.zlib.*;
import static org.junit.Assert.assertEquals;

public class UnitTest {
    @Test public void test() {
        System.out.println(zlibVersion().getString());
        assertEquals("1.2.13", zlibVersion().getString());
    }
}

