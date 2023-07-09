# Get the directory where the script resides
$scriptPath = Split-Path -Parent $MyInvocation.MyCommand.Path

# Get the root directory of the project
$projectRoot = Split-Path -Parent $scriptPath

# Change the directory temporarily
Push-Location -Path "$projectRoot/build"

# Run the tests using CTest
ctest --output-on-failure

# Prompt for user input before exiting
Write-Host "Press Enter to exit..."
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyUp')

# Return to the original directory
Pop-Location
