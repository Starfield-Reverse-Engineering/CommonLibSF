#Requires -Version 5

# args
param (
    [string]$PathIn,
    [string]$PathOut
)

$ErrorActionPreference = "Stop"

$SourceExt = @('.asm', '.c', '.cc', '.cpp', 'cppm', '.cxx', '.h', '.hpp', '.hxx', 'inc', '.inl', '.ixx', '.mxx')
$ConfigExt = @('.ini', '.json', '.toml', '.xml')
$DocsExt = @('.md')

function Normalize-Path {
    param (
        [string]$in
    )

    $out = $in -replace '\\', '/'
    while ($out.Contains('//')) {
        $out = $out -replace '//', '/'
    }
    return $out
}

function Resolve-Files {
    param (
        [string[]]$range = @('include', 'src', 'test')
    )

    process {
        Push-Location $PathIn
        $_generated = [System.Collections.ArrayList]::new(2048)

        try {
            foreach ($directory in $range) {
                Write-Host "[$PathIn/$directory]"

                Get-ChildItem "$PathIn/$directory" -Recurse -File -ErrorAction SilentlyContinue | Where-Object {
                    ($_.Extension -in ($SourceExt + $DocsExt))
                } | Resolve-Path -Relative | ForEach-Object {
                    Write-Host "`t<$_>"
                    $_generated.Add("`n`t`"$(Normalize-Path $_.Substring(2))`"") | Out-Null
                }
            }
        }
        finally {
            Pop-Location
        }

        return $_generated
    }
}

# @@SOURCEGEN
Write-Host "`tGenerating CMake sourcelist..."
Remove-Item "$PathOut/sourcelist.cmake" -Force -Confirm:$false -ErrorAction Ignore

$generated = 'set(SOURCES'
$generated += Resolve-Files
$generated += "`n)"
[IO.File]::WriteAllText("$PathOut/sourcelist.cmake", $generated)
