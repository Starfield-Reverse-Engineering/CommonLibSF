#Requires -Version 5

# args
param (
	[string]$PathIn
)

$ErrorActionPreference = "Stop"

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
	process {
		Push-Location "$PathIn/include"
		$_generated = [System.Collections.ArrayList]::new(2048)

		try {
			Get-ChildItem "$PathIn/include/RE" -Recurse -File -ErrorAction SilentlyContinue
			| Where-Object { ($_.Extension -eq '.h') } | Resolve-Path -Relative | ForEach-Object {
				if (!$_.EndsWith('Starfield.h')) {
					Write-Host "`t<$_>"
					$_generated.Add("`n#include `"$(Normalize-Path $_.Substring(2))`"") | Out-Null
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
Write-Host "`tGenerating Starfield.h..."
Remove-Item "$PathIn/Starfield.h" -Force -Confirm:$false -ErrorAction Ignore

$generated = '#pragma once

#include "SFSE/Impl/PCH.h"
'
$generated += Resolve-Files
$generated += "`n"
[IO.File]::WriteAllText("$PathIn/include/RE/Starfield.h", $generated)
