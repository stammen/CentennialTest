// CentennialTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

#include <Windows.h>
#include <VersionHelpers.h>
#include <AppModel.h>

bool IsRunningAsUwp()
{
	if (!IsWindows8OrGreater())
	{
		return false;
	}

	UINT32 length = 0;
	LONG result = GetCurrentPackageFullName(&length, nullptr);
	return result != APPMODEL_ERROR_NO_PACKAGE;
}

int main()
{
	std::cout << (IsRunningAsUwp() ? "Running as UWP" : "Not running as UWP") << std::endl;

	std::cout << "Press any key to exit..." << std::endl;
	char c = _getch();

    return 0;
}

