#Requires -Version 7.1

# args
param (
    [string]$PathIn
)

# test-path
if (!(Test-Path "$PathIn/CommonLibSF") -or !(Test-Path "$PathIn/CommonLibSF/vcpkg.json") -or !(Test-Path "$PathIn/README.md")) {
    Write-Output "VCPKG_SUCCESS=false" >> $env:GITHUB_OUTPUT
    exit
}

# commit time
$version = (Get-Date -AsUTC -Format "yyyy-MM-dd")

# update vcpkg
$vcpkg = [IO.File]::ReadAllText("$PathIn/CommonLibSF/vcpkg.json") | ConvertFrom-Json

$currVersion = $vcpkg.'version-date'

if($currVersion.Contains($version)) {
    $version = if ($currVersion.Contains('.')) {
        $identifiers = $currVersion.Split('.')
        "$($identifiers[0]).$([Int32]$identifiers[1] + 1)"
    }
    else {
        "$($currVersion).1"
    }
}

$vcpkg.'version-date' = $version
$vcpkg = $vcpkg | ConvertTo-Json -Depth 9 | ForEach-Object { $_ -replace "(?m)  (?<=^(?:  )*)", "  " }
[IO.File]::WriteAllText("$PathIn/CommonLibSF/vcpkg.json", $vcpkg)

# update readme
$readme = [IO.File]::ReadAllLines("$PathIn/README.md")
$readme = $readme -replace "(?<=label=vcpkg%20registry&message=).+?(?=&color)", $version
[IO.File]::WriteAllLines("$PathIn/README.md", $readme)

# status
Write-Output "VCPKG_SUCCESS=true" >> $env:GITHUB_OUTPUT
Write-Output "VCPKG_VERSION=$version" >> $env:GITHUB_OUTPUT
