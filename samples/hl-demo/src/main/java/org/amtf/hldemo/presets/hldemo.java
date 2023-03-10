package org.amtf.hldemo.presets;

import org.bytedeco.javacpp.*;
import org.bytedeco.javacpp.annotation.*;
import org.bytedeco.javacpp.tools.*;

@Properties(
//    value = {
//        @Platform(include = "<zlib.h>", link = "z@.1#"),
//        @Platform(value = "windows", link = "zlib#")
//    },
//    value = {
//        @Platform(include = "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/src/hl.h", link = "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/build/hl"),
//    },
    value = {
        @Platform(include = {
                "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/src/include/licensecc.h",
                "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/src/include/public_key.h",
                "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/src/include/licensecc_properties.h",
                "D:/IdeaProjects/gradle-javacpp/samples/hl-demo/hl-demo-cpp/src/include/datatypes.h",
        }, link = {"C:/c-project/licensecc/build/src/library/licensecc_static", "bcrypt"}),
    },
    target = "org.amtf.hldemo",
    global = "org.amtf.hldemo.global.hldemo"
)
public class hldemo implements InfoMapper {
    static { Loader.checkVersion("org.amtf", "hldemo"); }

    public void map(InfoMap infoMap) {
        infoMap.put(new Info("LCC_EVENT_TYPE", "LCC_API_HW_IDENTIFICATION_STRATEGY").cppTypes().enumerate());
        infoMap.put(new Info("FIND_LICENSE_NEAR_MODULE", "FIND_LICENSE_WITH_ENV_VAR").cppTypes("bool"));
        infoMap.put(new Info("PRODUCT_NAME").skip());
        infoMap.put(new Info("LCC_VERIFY_MAGIC").cppText("#define LCC_VERIFY_MAGIC (lic_info.m_magic == 0)"));
        infoMap.put(new Info("size_t").cast().valueTypes("int").pointerTypes("IntPointer"));
//        infoMap.put(new Info("PUBLIC_KEY").cppTypes("char *"));
//        infoMap.put(new Info("PUBLIC_KEY").cppTypes("const unsigned char"));
        infoMap.put(new Info("PUBLIC_KEY").cppTypes("uint8_t**").cppText("1234567"));
        infoMap.put(new Info("LCC_BARE_TO_METAL_STRATEGIES", "LCC_VM_STRATEGIES", "LCC_VM_STRATEGIES", "LCC_LXC_STRATEGIES", "LCC_DOCKER_STRATEGIES", "LCC_CLOUD_STRATEGIES").skip());
    }
}
