cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# generates a compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(javacpp-demo)

if(MSVC)
    # https://learn.microsoft.com/en-us/cpp/build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8?view=msvc-170
    # use the /utf-8 option to specify both the source and execution character sets as encoded by using UTF-8.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

add_library(hl STATIC src/hl.cpp src/hl-util.cpp)
add_library(licensecc STATIC src/include/licensecc.cpp)
add_executable(demo src/demo.cpp)
target_link_libraries(demo PRIVATE hl)

add_executable(lcc_demo src/lcc_demo.cpp)
target_include_directories(lcc_demo PRIVATE "C:/c-project/licensecc/include/licensecc" "C:/c-project/licensecc/projects/DEFAULT/include/licensecc/DEFAULT")
target_link_libraries(lcc_demo PRIVATE C:/c-project/licensecc/build/src/library/licensecc_static.lib bcrypt.lib)


find_package(cryptopp CONFIG REQUIRED)

add_executable(rsa_demo src/rsa_demo.cpp)
target_link_libraries(rsa_demo PRIVATE cryptopp::cryptopp)

add_executable(rsaes-oaep-demo src/rsaes-oaep-demo.cpp)
target_link_libraries(rsaes-oaep-demo PRIVATE cryptopp::cryptopp)
target_link_libraries(rsa_demo PRIVATE cryptopp::cryptopp)

add_executable(rsaes-oaep-sha256 src/rsaes-oaep-sha256.cpp)
target_link_libraries(rsaes-oaep-sha256 PRIVATE cryptopp::cryptopp)