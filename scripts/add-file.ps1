$workspace = Resolve-Path "$PSScriptRoot/../"
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
$lastAction = $true
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
            $files = $files[1..$($files.Length - 1)]
            $files | % { Modify-File $_ $true }
            $script:lastFile = $files
            $script:lastAction = $true
            break
        }
    }
}
