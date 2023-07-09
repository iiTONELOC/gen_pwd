# $programName = "gen_pwd.exe" 
# $buildScriptPath = Join-Path -Path $PSScriptRoot -ChildPath "build.ps1"

# # Run the build script
# & $buildScriptPath -buildType "Release"

# # Get the full path to the program executable
# $programPath = Join-Path -Path $buildDir -ChildPath $programName

# # Add the program's path to the PATH environment variable
# $existingPath = [Environment]::GetEnvironmentVariable("PATH", "User")
# $newPath = "$programPath;$existingPath"
# [Environment]::SetEnvironmentVariable("PATH", $newPath, "User")

# Write-Host "Installation completed successfully."

$programName = "gen_pwd.exe" 
$buildScriptPath = Join-Path -Path $PSScriptRoot -ChildPath "build.ps1"

# Run the build script
& $buildScriptPath -buildType "Release"

# Set the build directory
$buildDir = "E:/Code/C/gen_pwd/build"  # Update this path to the actual build directory

# Get the full path to the program executable
$programPath = Join-Path -Path $buildDir -ChildPath $programName

# Add the program's path to the PATH environment variable
$existingPath = [Environment]::GetEnvironmentVariable("PATH", "User")
$newPath = "$programPath;$existingPath"
[Environment]::SetEnvironmentVariable("PATH", $newPath, "User")

Write-Host "Installation completed successfully."
