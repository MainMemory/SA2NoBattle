// SA2NoBattle.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"

char nopjmp[] = { 0x90, 0xE9 };

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		WriteData<2>((void*)0x458A10, 0x90); // intro
		WriteData<6>((void*)0x667A74, 0x90); // menu bg
		WriteData((void*)0x667F27, nopjmp); // more menu
		WriteData<6>((void*)0x66F8DD, 0x90); // menu
		WriteData((void*)0x66FEB4, nopjmp); // probably menu
		WriteData<6>((void*)0x670449, 0x90); // title logo
		WriteData<2>((void*)0x67B723, 0x90); // sound test disc
		WriteData<2>((void*)0x688B0B, 0x90); // 2P stage selection?o
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}

