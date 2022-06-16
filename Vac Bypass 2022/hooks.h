/*

		yordu.

*/



#pragma once
#include <Windows.h>
#include <fstream>
#include <string>
#include <TlHelp32.h>

#include "scanner.h"

#include "detours.h"
#pragma comment(lib, "detours.lib")

#pragma warning (disable : 4996)

typedef int(_cdecl* tFn1)(HANDLE ProcessHandle, int a2);
inline tFn1 pFn1;

int _cdecl hkTfn1(HANDLE ProcessHandle, int a2);

typedef DWORD(_stdcall* tFn2)(HANDLE TargetHandle, int a2, int a3);
inline tFn2 pFn2;

DWORD _stdcall hkTfn2(HANDLE TargetHandle, int a2, int a3);

typedef bool(_cdecl* tFn3)(DWORD dwProcessId, int a2, int a3);
inline tFn3 pFn3;

bool _cdecl hkTfn3(DWORD dwProcessId, int a2, int a3);

typedef char(_stdcall* tFn4)();
inline tFn4 pFn4;

char _stdcall hkTfn4();

typedef int(__thiscall* tFn5)(char* p_this);
inline tFn5 pFn5;

char _stdcall hkTfn5(char* p_this);

typedef DWORD* (__thiscall* tFn6)(DWORD* p_this);
inline tFn6 pFn6;

DWORD* _stdcall hkTfn6(DWORD* p_this);

typedef char(__thiscall* tFn7)(BYTE* p_this, int a2, HANDLE TargetHandle, int a4, int a5, int a6);
inline tFn7 pFn7;

char _stdcall hkTfn7(BYTE* p_this, int a2, HANDLE TargetHandle, int a4, int a5, int a6);

typedef SIZE_T(WINAPI* tVirtualQuery)(LPCVOID lpAdress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
inline tVirtualQuery pVirtualQuery;

static SIZE_T WINAPI hkVirtualQuery(LPCVOID lpAdress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);

typedef SIZE_T(WINAPI* tVirtualQueryEx)(HANDLE hProcess, LPCVOID lpAdress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
inline tVirtualQueryEx pVirtualQueryEx;

static SIZE_T WINAPI hkVirtualQueryEx(HANDLE hProcess, LPCVOID lpAdress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);

typedef BOOL(WINAPI* tProcess32NextW)(HANDLE hSnapShot, LPPROCESSENTRY32W lppe);
inline tProcess32NextW pProcess32NextW;

static BOOL WINAPI hkProcess32NextW(HANDLE hSnapShot, LPPROCESSENTRY32W lppe);

typedef BOOL(WINAPI* tModule32NextW)(HANDLE hSnapShot, LPMODULEENTRY32W lppe);
inline tModule32NextW pModule32NextW;

static BOOL WINAPI hkModule32NextW(HANDLE hSnapShot, LPMODULEENTRY32W lppe);

typedef BOOL(WINAPI* tIsDebuggerPresent)();
inline tIsDebuggerPresent pIsDebuggerPresent;

static BOOL WINAPI hkIsDebuggerPresent();

typedef NTSTATUS(NTAPI* tNtReadVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG BufferSize, PULONG NumberOfBytesRead);
inline tNtReadVirtualMemory pNtReadVirtualMemory;

static NTSTATUS hkNtReadVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG BufferSize, PULONG NumberOfBytesRead);

bool InitVACHooks(void* DllImageBase);