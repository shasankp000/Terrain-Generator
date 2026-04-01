# Terrain-Generator (C_recap)

This repository contains a small C example in `C_recap/basics.c` and simple build helpers for Windows using gcc.

Quick steps

1. Install GCC on Windows if you don't have it. Two recommended options:
   - MSYS2 (mingw-w64): https://www.msys2.org/ — after installing, run `pacman -Syu` and then `pacman -S mingw-w64-x86_64-gcc` and add `C:\msys64\mingw64\bin` to PATH.
   - MinGW-w64: https://winlibs.com/ or via installer distributions. Add the `bin` directory to PATH.

MinGW-w64 (detailed)

1. Download MinGW-w64 from a trusted provider. Two common choices:
   - WinLibs standalone build: https://winlibs.com/
   - MSYS2 installer provides mingw-w64 (see above) if you prefer pacman-managed packages.

2. If using WinLibs (no package manager):
   - Download the appropriate archive for your architecture (e.g., x86_64-posix-seh).
   - Extract the archive to a location like `C:\mingw-w64\win64`.
   - The GCC binaries will be in `C:\mingw-w64\win64\bin` (adjust for the path you chose).

3. Add the bin folder to your user or system PATH (so `gcc` is available from cmd.exe):
   - Open Start -> Edit environment variables for your account -> Environment Variables.
   - Under 'User variables' or 'System variables' find `Path` and Edit -> New -> paste `C:\mingw-w64\win64\bin` (use your actual path).
   - Open a new cmd.exe window and run:

```bat
where gcc
gcc --version
```

4. Back in the workspace, run the build script from cmd.exe (not PowerShell):

```bat
build.bat
```

If you prefer PowerShell, run:

```powershell
& .\build.bat
```

If `where gcc` shows a path and `gcc --version` prints version info, the `build.bat` script will compile `C_recap\basics.c` into `C_recap\basics.exe`.

2. From the workspace root (where this README is), run the build script in cmd.exe:

```
build.bat
```

Or use the Makefile if you have GNU make available on Windows (e.g., via MSYS2):

```
make
```

3. The built executable will be at `C_recap\basics.exe`.

If gcc is not on PATH, `build.bat` will exit with an error and point you to installation instructions.
