#include <Windows.h>
#include <iostream>

#include "scanner.h"
#include "hooks.h"

void MainThread(HMODULE hModule) {
	HMODULE hSteamService = GetModuleHandleA("steamservice.dll");

	if (hSteamService) {
		if (InitVACHooks((void*)hSteamService))
			MessageBoxA(0, "VAC Aktif. CSGO'yu baslat.", "VAC Bypass", MB_OK);
		else
			MessageBoxA(0, "Hata tespit edildi, steam'i kapatin.", "VAC Bypass", MB_OK);
	}
	else
		MessageBoxA(0, "steamservice.dll Bulunamadi. Lutfen steam'i yonetici olarak calistirin...", "VAC Bypass", MB_OK);

	FreeLibraryAndExitThread(hModule, 0);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPARAM lParam) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	}
}