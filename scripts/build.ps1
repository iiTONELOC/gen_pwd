param (
    [string]$buildType = "Debug"
    # for a release build, use "Release"
    #  .\build.ps1 -buildType "Release"
)
# command run by Visual Studio Code when the build process is started, this configures the build system
$cmakeCommand = @"
    "C:\Program Files\CMake\bin\cmake.EXE" --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=$buildType -DCMAKE_C_COMPILER:FILEPATH=C:\msys64\mingw64\bin\gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=C:\msys64\mingw64\bin\g++.exe -S "E:/Code/C/gen_pwd" -B "E:/Code/C/gen_pwd/build" -G "MinGW Makefiles"
"@

# cmake build command as run by Visual Studio Code when the build system is completed
$buildCommand = @"
    "C:\Program Files\CMake\bin\cmake.EXE" --build "E:/Code/C/gen_pwd/build" --config $buildType
"@

& cmd.exe /C $cmakeCommand
& cmd.exe /C $buildCommand

# set the build type to "Debug" by default
$buildType = "Debug"