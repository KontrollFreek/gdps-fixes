#include <Windows.h>

DWORD WINAPI func(void *me)
{
    auto proc = GetCurrentProcess();
    auto base = reinterpret_cast<char *>(GetModuleHandleA(nullptr));
    // practice music
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x20D143), "\x90\x90", 2, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x20A563), "\x90\x90", 2, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x20A595), "\x90\x90", 2, NULL);
    // text length
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x21ACB), "\xeb\x04", 2, NULL);
    // copy hack
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x179B8E), "\x90\x90", 2, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x176F5C), "\x8b\xca\x90", 3, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x176FE5), "\xb0\x01\x90", 3, NULL);
    // object bypass
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x73169), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x856A4), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x87B17), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x87BC7), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x87D95), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x880F4), "\xff\xff\xff\x7f", 4, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x160B06), "\xff\xff\xff\x7f", 4, NULL);
    // default song bypass
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x174407), "\x90\x90", 2, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x174411), "\x90\x90\x90", 3, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x174456), "\x90\x90", 2, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0x174460), "\x90\x90\x90", 3, NULL);
    // icon hack
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0xC50A8), "\xb0\x01\x90\x90\x90", 5, NULL);
    WriteProcessMemory(proc, reinterpret_cast<void *>(base + 0xC54BA), "\xb0\x01\x90\x90\x90", 5, NULL);

    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(me), 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
        if (auto h = CreateThread(nullptr, 0, &func, mod, 0, nullptr))
            CloseHandle(h);
    return TRUE;
}