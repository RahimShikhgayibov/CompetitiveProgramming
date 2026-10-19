# Compile + run a solution.
#   .\run.ps1 .\CSES\Graph\1666_building_roads.cpp
#
# Compiles with -static (without it g++ may pick the wrong runtime DLL and crash silently).
# On success runs the program with input.txt: first looks next to the .cpp, then in the repo root.
# No input.txt -> program waits for keyboard input (that is not an error).

param([Parameter(Mandatory = $true)][string]$File)

$src = (Resolve-Path $File -ErrorAction Stop).Path
$exe = [IO.Path]::ChangeExtension($src, ".exe")

g++ -std=c++17 -O2 -Wall -static "$src" -o "$exe"
if ($LASTEXITCODE -ne 0) {
    Write-Host "Compile error" -ForegroundColor Red
    exit 1
}

$inFile = Join-Path (Split-Path $src) "input.txt"
if (-not (Test-Path $inFile)) { $inFile = Join-Path $PSScriptRoot "input.txt" }

# Start-Process redirect instead of Get-Content | exe: PowerShell 5.1 pipe can mangle the input
if (Test-Path $inFile) {
    Write-Host "--- input: $inFile" -ForegroundColor DarkGray
    $p = Start-Process -FilePath $exe -RedirectStandardInput $inFile -NoNewWindow -Wait -PassThru
} else {
    Write-Host "--- no input.txt, type input (Ctrl+Z, Enter to finish)" -ForegroundColor DarkGray
    $p = Start-Process -FilePath $exe -NoNewWindow -Wait -PassThru
}

if ($p.ExitCode -ne 0) {
    Write-Host "--- exit code $($p.ExitCode) (runtime error?)" -ForegroundColor Red
}
