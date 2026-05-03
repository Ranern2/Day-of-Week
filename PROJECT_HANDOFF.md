# Project Handoff

Created: 2026-05-03
Original workspace: c:\Users\sameerb\day-of-week-cpp
Working copy for other account: d:\AnishProjects\day-of-week-cpp

## What was copied
This folder is a full copy of the current workspace, including:
- source files
- static web app files
- the .vscode folder
- current native build outputs such as .exe, .obj, .ilk, and .pdb files

The copied workspace currently contains:
- index.html
- icon.svg
- main.cpp
- main.exe
- main.ilk
- main.obj
- main.pdb
- manifest.webmanifest
- sw.js
- vc140.pdb
- .vscode/build_msvc.bat
- .vscode/tasks.json
- .vscode/launch.json
- .vscode/settings.json

## Current project notes
- This is not a git repository right now.
- VS Code has a build task named "Build active file (MSVC)".
- The task uses .vscode/build_msvc.bat.
- That script uses vswhere to locate a Visual Studio installation dynamically.
- The build requires Visual Studio 2017+ with C++ tools installed.
- The compile command uses MSVC with C++20, exceptions enabled, and debug info.

## How to reopen under the other local Windows account
1. Sign into the other local Windows account.
2. Open VS Code.
3. Open the folder d:\AnishProjects\day-of-week-cpp.
4. Open main.cpp if you want to build/debug the C++ program.
5. Run the default build task from Terminal > Run Build Task, or run the task named "Build active file (MSVC)".
6. If you want to debug, use the launch configuration named "Debug active file (MSVC)".
7. Open index.html if you want to continue working on the static web app side.

## Requirements on the other account
- VS Code installed.
- C/C++ support in VS Code if you want debugging and problem matching.
- Visual Studio or Build Tools with the x64 C++ toolchain installed.
- vswhere available at:
  %ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe

## What will not carry over automatically
These items are tied to the current VS Code profile or Windows account and are not something I can export fully from here:
- signed-in VS Code account
- GitHub Copilot sign-in state
- open editor tabs and layout state
- terminal session history and running processes
- extension sign-ins and per-user VS Code global settings
- this live chat session state inside Copilot Chat

## Session summary
Recent session context worth preserving:
- You asked whether Vercel supports simple HTML apps. The answer was yes: static HTML/CSS/JS apps are a normal fit for Vercel.
- You asked which account the current VS Code session is using. I could not inspect the signed-in VS Code account directly from available tools.
- Repo-specific build note: the MSVC task should stay as a process task and the build script should keep using vswhere instead of a hardcoded Visual Studio path.

## Fast sanity checks after switching accounts
- Verify the build task is visible in VS Code.
- Run the build task on main.cpp.
- Confirm main.exe is regenerated successfully if you rebuild.
- If you need web preview behavior, open index.html in the browser or use your usual local static server.
