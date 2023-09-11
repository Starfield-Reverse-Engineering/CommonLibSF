<#
.SYNOPSIS
this script is for adding/modifying/commiting RE files alongside the CLib development.

.EXAMPLE
to add new RE file (.h and .cpp), just input the file name, multiple files are separated by space
: TESNewUndefinedClass BGSInferiorStructure NiPoint200

to del RE file, prepend -d
: -d TESNewUndefinedClass BGSInferiorStructure NiPoint200

to undo last action, use -u
: -u
*can only revert last commit, cannot undo-revert last commit

to bring RE file changes into a current ongoing visual studio project, use -r and do a build inside visual studio
: -r

use ctrl ^ c to exit
#>


$workspace = Resolve-Path "$PSScriptRoot/../"
Push-Location $workspace
$include = "$workspace/CommonLibSF/include/RE"
$src = "$workspace/CommonLibSF/src/RE"


function Modify-File {
    param (
        [string]$file,
        [bool]$add = $true
    )

    $abbr = "$($file[0])"
    if ($add) {
        "#pragma once`n`nnamespace RE`n{`n}`n" | Out-File "$include/$abbr/$file.h" utf8
        "#include `"RE/$($abbr.ToUpper())/$file.h`"`nnamespace RE`n{`n}`n" | Out-File "$src/$abbr/$file.cpp" utf8

        Write-Host "add [$file]"
    }
    else {
        Remove-Item "$include/$abbr/$file.h" -Force -Confirm:$false -ErrorAction:SilentlyContinue | Out-Null
        Remove-Item "$src/$abbr/$file.cpp" -Force -Confirm:$false -ErrorAction:SilentlyContinue | Out-Null
        Write-Host "del [$file]"
    }
}


$lastFile = ""
# 0 del
# 1 add
# 2 revert
# 3 commit
$lastAction = 0

while ($true) {
    $cmd = Read-Host " "

    switch ($cmd[0]) {
        '-' {
            # actions
            switch ($cmd[1]) {
                'd' {
                    # del
                    $files = $cmd.Split(' ')
                    $files = $files[1..$($files.Length - 1)]
                    $files | % { Modify-File $_ $false }
                    $script:lastFile = $files
                    $script:lastAction = $false
                    break
                }
                'r' {
                    # refresh
                    & "$workspace/.github/make-directives.ps1" "$workspace/CommonLibSF"

                    $cmake = "$workspace/CommonLibSF/CMakeLists.txt"
                    [IO.File]::WriteAllText($cmake, [IO.File]::ReadAllText($cmake))
                    break
                }
                'u' {
                    # undo
                    $script:lastAction = !$script:lastAction
                    $script:lastFile | % { Modify-File $_ $script:lastAction }
                    break
                }
            }
            break
        }
        default {
            $files = $cmd.Split(' ')
            $files | % { Modify-File $_ $true }
            $script:lastFile = $files
            $script:lastAction = $true
            break
        }
    }
}
