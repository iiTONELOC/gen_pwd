# Password Generator

![License](https://img.shields.io/github/license/iiTONELOC/gen_pwd?style=plastic&label=License)
![Languages](https://img.shields.io/github/languages/count/iitoneloc/gen_pwd?style=plastic&label=Languages) ![git-hub-top-language](https://img.shields.io/github/languages/top/iiTONELOC/gen_pwd?color=blue&label=C&style=plastic)

is a simple password generator written in C.

## Description

While nothing is ever inherently secure. The generator tries to guarantee randomness using the following checks:

- Passwords must be between 12 and 128 characters.
- Must include, lowercase, uppercase, numbers, and special characters.
- No whitespace
- Must have a special character within the first 7 characters
- First and last characters must be different
- First and last characters must be a letter or number

## Screenshot

![Screenshot](https://images.unsplash.com/photo-1550751827-4bd374c3f58b?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1200&q=80)

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Tests](#tests)
- [Contact](#contact)
- [LICENSE](#license)

## Features

- To ensure randomness, we utilize the RAND_bytes function from OpenSSL.

  [Read more here](https://www.openssl.org/docs/manmaster/man3/RAND_bytes.html).

## Prerequisites

- A file from the OpenSSL Library is required to compile the project,

  Clone the OpenSSL repo to a location of your choosing:

  ```bash
  git clone https://github.com/openssl/openssl.git <path to folder>
  ```

  Modify the CMakeList.txt file to reflect the new location:

  ```txt
  12 # Set the path to the OpenSSL installation
  13 set(OPENSSL_ROOT_DIR <path to OpenSSL repo>)
  ```

- MINGW-W64 GCC Compiler for Windows. [Installation instructions can be found here](https://www.msys2.org/)

## Installation

Navigate to a folder of your choosing and clone the repository:

```bash
git clone https://github.com/iiTONELOC/gen_pwd.git

# navigate to the project folder
cd gen_pwd
```

A powershell script is provided for building and installing the generator.

From the project root run the install script:

```bash
  .\scripts\install.ps1

  # expected output
  Not searching for unused variables given on the command line.
  -- The C compiler identification is GNU 12.2.0
  -- Detecting C compiler ABI info
  -- Detecting C compiler ABI info - done
  -- Check for working C compiler: C:/msys64/mingw64/bin/gcc.exe - skipped
  -- Detecting C compile features
  -- Detecting C compile features - done
  -- Found OpenSSL: C:/msys64/mingw64/lib/libcrypto.dll.a (found version "1.1.1q")
  -- Configuring done
  -- Generating done
  -- Build files have been written to: E:/Code/C/gen_pwd/build
  [  7%] Building C object CMakeFiles/utils.dir/src/utils/utils.c.obj
  [ 14%] Linking C static library libutils.a
  [ 14%] Built target utils
  [ 21%] Building C object CMakeFiles/gen_pwd.dir/main.c.obj
  [ 28%] Linking C executable gen_pwd.exe
  [ 28%] Built target gen_pwd
  [ 35%] Building C object CMakeFiles/test_safely_access_char_from_string.dir/tests/test_safely_access_char_from_string.c.obj
  [ 42%] Linking C executable test_safely_access_char_from_string.exe
  [ 42%] Built target test_safely_access_char_from_string
  [ 50%] Building C object CMakeFiles/test_random_char_and_string.dir/tests/test_random_char_and_string.c.obj
  [ 57%] Linking C executable test_random_char_and_string.exe
  [ 57%] Built target test_random_char_and_string
  [ 64%] Building C object CMakeFiles/test_random_int.dir/tests/test_random_int.c.obj
  [ 71%] Linking C executable test_random_int.exe
  [ 71%] Built target test_random_int
  [ 78%] Building C object CMakeFiles/test_password_checks.dir/tests/test_password_checks.c.obj
  [ 85%] Linking C executable test_password_checks.exe
  [ 85%] Built target test_password_checks
  [ 92%] Building C object CMakeFiles/test_password_generation.dir/tests/test_generate_password.c.obj
  [100%] Linking C executable test_password_generation.exe
  [100%] Built target test_password_generation
  Installation completed successfully.
```

## Usage

```bash
# With length specified, accepts lengths of 12-128
gen_pwd -l 40
# example output -> 6/pJb;Rpw|68'A3)|k#+)=K95]BGDZD6eSK=em:N

# No length specified
gen_pwd
# example output -> q+bW']OB0F=5
```

## Tests

TDD type approach was implemented to ensure the utility functions and the program operate as expected. Tets can be verified after the project has been complied, via the install step.

```bash
 # manual install - not necessary if installed
 .\scripts\build.ps1

 # run tests
 .\scripts\test.ps1
```

## Contact

If you have any questions please feel free to reach me at [anthonytropeano@protonmail.com](mailto:anthonytropeano@protonmail.com)

Or find me on GitHub @ [iiTONELOC](https://github.com/iiTONELOC)

## License

This project is licensed with the MIT license. A copy can be found [HERE](./LICENSE)
