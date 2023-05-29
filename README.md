# This is a guide on how to run the project
The documentation is on file documentation.txt

## Requirements

It is recommended to clone the project from my github - https://github.com/DekataBG/GameOfLifeGUI, not from the ZIP I uploaded.

This works on Windows, Mac, and Linux. You'll need `cmake` and a C++ compiler (tested on `clang`, `gcc`, and MSVC).

Linux builds require the GTK3 library and headers installed in the system.

If you use VS Code you must also install the extension CodeLLDB by Vadim Chugunov and Native Debug by WebFreak.

## Building

To build the project, you have to use VS Code, because I am not sure whether everything will successfully be linked by Visual Studio. 

If you are on Linux you won't have problems with running cmake. If you are on Windows, you have to open x86 Native Tools Command Prompt for VS (it is in the Visual Studio Folder) and then from there open your folder with the command "code <path-to-project>". Now you should be able to run cmake. I'm not sure about MAC, but I suppose, as with Linux, you should't have problems. 

In the terminal you have to write these 2 commands: 
cmake -S. -Bbuild
cmake --build build
They might take quite a bit of time, so you have to be ready to wait.

This will create a directory named `build` and create all build artifacts there. The main executable can be found in the `build/subprojects/Build/wx_cmake_template_core` folder.

## Running

In the left down corner there is a green triangle with cog on its left - the "Select and start debug configuration" button. Click it and select your OS. If everything is okay, the program should start. 

## Notes

For details, see the [blog post](https://www.justdevtutorials.com/post/wxwidgets-cmake/) and the [video](https://www.youtube.com/watch?v=MfuBS9n5_aY) tutorial showcasing the installation on Linux, Windows, and Mac OS X.
