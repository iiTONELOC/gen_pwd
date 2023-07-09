cmake_minimum_required(VERSION 3.18)
project(gen_pwd VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

# Set the path to the desired C compiler
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")

# Set the path to the desired C++ compiler
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

# Set the path to the OpenSSL installation
set(OPENSSL_ROOT_DIR "E:/Code/C/c_libs")

include(CTest)
enable_testing()

# Locate the OpenSSL package
find_package(OpenSSL REQUIRED)


# Include the OpenSSL headers
include_directories(${OPENSSL_INCLUDE_DIR})

# Add the utils library
add_library(utils STATIC src/utils/utils.c src/utils/utils.h)

# Add the main executable
add_executable(gen_pwd main.c src/utils/utils.h)

# Link libraries to the main executable
target_link_libraries(gen_pwd PRIVATE utils ${OPENSSL_LIBRARIES})

# Add the test executables
add_executable(test_safely_access_char_from_string tests/test_safely_access_char_from_string.c)
add_executable(test_random_char_and_string tests/test_random_char_and_string.c)
add_executable(test_random_int tests/test_random_int.c)
add_executable(test_password_checks tests/test_password_checks.c)
add_executable(test_password_generation tests/test_generate_password.c)

# Link libraries to the test executables
target_link_libraries(test_safely_access_char_from_string PRIVATE utils)
target_link_libraries(test_random_int PRIVATE utils)
target_link_libraries(test_random_char_and_string PRIVATE utils)
target_link_libraries(test_password_checks PRIVATE utils)
target_link_libraries(test_password_generation PRIVATE utils)

# Link OpenSSL libraries to test executables
target_link_libraries(test_safely_access_char_from_string PRIVATE ${OPENSSL_LIBRARIES})
target_link_libraries(test_random_int PRIVATE ${OPENSSL_LIBRARIES})
target_link_libraries(test_random_char_and_string PRIVATE ${OPENSSL_LIBRARIES})
target_link_libraries(test_password_checks PRIVATE ${OPENSSL_LIBRARIES})
target_link_libraries(test_password_generation PRIVATE ${OPENSSL_LIBRARIES})

# Add the test to the CTest test suite
add_test(NAME TestSafelyAccessCharFromString COMMAND test_safely_access_char_from_string)
add_test(NAME TestRandomInt COMMAND test_random_int)
add_test(NAME TestRandomCharAndString COMMAND test_random_char_and_string)
add_test(NAME TestPasswordChecks COMMAND test_password_checks)
add_test(NAME TestPasswordGeneration COMMAND test_password_generation)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Link the utils folder for both the main executable and test executables
target_include_directories(gen_pwd PRIVATE src/utils)
target_include_directories(test_safely_access_char_from_string PRIVATE src/utils)
target_include_directories(test_random_int PRIVATE src/utils)
target_include_directories(test_random_char_and_string PRIVATE src/utils)
target_include_directories(test_password_checks PRIVATE src/utils)
target_include_directories(test_password_generation PRIVATE src/utils)
