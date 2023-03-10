cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# generates a compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(javacpp-demo)

add_library(hl STATIC src/hl.cpp src/hl-util.cpp)
add_library(licensecc STATIC src/include/licensecc.cpp)
add_executable(demo src/demo.cpp)
target_link_libraries(demo PRIVATE hl)

add_executable(lcc_demo src/lcc_demo.cpp)
target_include_directories(lcc_demo PRIVATE "C:/c-project/licensecc/include/licensecc" "C:/c-project/licensecc/projects/DEFAULT/include/licensecc/DEFAULT")
target_link_libraries(lcc_demo PRIVATE C:/c-project/licensecc/build/src/library/licensecc_static.lib bcrypt.lib)