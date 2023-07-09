# Get the directory where the script resides
$scriptPath = Split-Path -Parent $MyInvocation.MyCommand.Path

# Get the root directory of the project
$projectRoot = Split-Path -Parent (Split-Path -Parent $scriptPath)

# Specify the build folder path
$buildFolderPath = Join-Path $projectRoot "gen_pwd/build"

# Change the directory temporarily
Push-Location -Path $buildFolderPath

# Specify the executable name
$executableName = "gen_pwd.exe"

# Pass all the arguments provided to the script to the executable
$arguments = $args

# Check if the executable file exists
$executablePath = Join-Path $buildFolderPath $executableName

if (Test-Path $executablePath -PathType Leaf) {
    # Execute the C program with arguments
    & $executablePath $arguments
}
else {
    Write-Host "Executable not found: $executablePath"
}

# Return to the original directory
Pop-Location
