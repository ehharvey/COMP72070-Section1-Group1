$template=@"


cc_library(
    name = #NAME,
    srcs = [#SOURCE],
    hdrs = [#HEADER],
    visibility = ["//Communication:__pkg__"],
    deps = [#DEPS]
)
"@

cd .\Communication
rm BUILD

echo 'load("@rules_cc//cc:defs.bzl", "cc_library")' | out-File .\BUILD -Encoding ascii

ls | Where-Object {$_.Name.EndsWith(".h")} | ForEach-Object {
    $name=($_.Name.Split(".")[0])
    $header=$_.tostring()
    $source=($_.Name.Split(".")[0] + ".cpp")
    
    $deps=(Get-Content $header | Select-String -Pattern "^#include `"" | ForEach-Object {$_.ToString()} | ForEach-Object {$_.split(" ")[1].trim('"').split(".")[0]} | ForEach-Object { "`n`t`"//Communication:" + $_ +"`","})   
    
    if (Test-Path -Path $source)
    {
        $source=$('"' + $source + '"')
    }
    else {
        $source = ""
    }
    
    $template -replace "#NAME", $('"' + $name + '"') `
    -replace "#SOURCE", $source `
    -replace "#HEADER", $('"' + $header + '"')  `
    -replace "#DEPS", ($deps + "`n`t")                                                           
} | Out-File .\BUILD -Append -Encoding ascii

cd ..