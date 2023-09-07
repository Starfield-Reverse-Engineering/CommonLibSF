#Requires -Version 5

# args
param (
    [string]$PathIn
)

# test-path
if (!(Test-Path "$PathIn/CommonLibSF") -or !(Test-Path "$PathIn/CommonLibSF/vcpkg.json") -or !(Test-Path "$PathIn/README.md")) {
    Write-Output "::set-output name=VCPKG_SUCCESS::false"
    exit
}

# commit time
$version = (Get-Date -AsUTC -Format "yyyy-MM-dd")

# update vcpkg
$vcpkg = [IO.File]::ReadAllText("$PathIn/CommonLibSF/vcpkg.json") | ConvertFrom-Json
$vcpkg.'version-date' = $version
$vcpkg = $vcpkg | ConvertTo-Json -Depth 9 | ForEach-Object { $_ -replace "(?m)  (?<=^(?:  )*)", "  " }
[IO.File]::WriteAllText("$PathIn/CommonLibSF/vcpkg.json", $vcpkg)

# update readme
$readme = [IO.File]::ReadAllLines("$PathIn/README.md")
$readme = $readme -replace "(?<=label=vcpkg&message=).+?(?=&color)", $version
[IO.File]::WriteAllLines("$PathIn/README.md", $readme)

# status
Write-Output "::set-output name=VCPKG_SUCCESS::true"
Write-Output "::set-output name=VCPKG_VERSION::$version"
