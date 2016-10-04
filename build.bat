@echo off
setlocal

SET SRC=%~dp0

call "%VS140COMNTOOLS%vsvars32.bat"

msbuild %SRC%\CentennialTest.sln /p:Configuration="Release" /p:Platform="x86" /m

"C:\Program Files (x86)\NSIS\Bin\makensis.exe" %SRC%\installer.nsi

DesktopAppConverter.exe -Installer %SRC%\installer.exe -InstallerArguments "/S" -Destination %SRC%\AppxOut -PackageName "CentennialTest" -Publisher "CN=stamm" -Version 0.0.0.1 -MakeAppx -Verbose -Sign -AppExecutable CentennialTest.exe

pause
endlocal
