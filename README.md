# SSE-ImGui

This is a mod for Skyrim SE, providing SKSE plugins a binding to 
[ImGui](https://github.com/ocornut/imgui). ImGui is nice small library for overlaying graphical
interfaces over, usually, 3d accelerated applications. Small demo is included in `share/demo`.

Flow goes on as:
1. During SKSE's Post Load message a SSE-GUI listener is registered.
2. During SKSE's Input loaded message, SSE-GUI provides its interface, where basic ImGui loops
   are registered. SSE-ImGui interface is broadcasted.
3. Plugins can register in that interface and render with the provided ImGui interface (see the
   demo).

SSE-ImGui sniffs by default Windows messages and "wraps" its listeners within a common ImGui render
loop. When the `VK_INSERT` key is pressed, it toggles the message sniff. This allows switching
between gameplay and the GUI (by no accident this key matches the SSE-GUI key for disabling the
keyboard and mouse for the game).

This project does not intend to provide teach how to use ImGui, it merely provides a convenient
interface to it.

## References

* ImGui: https://github.com/ocornut/imgui
* CImGui: https://github.com/cimgui/cimgui
* SSE-GUI: https://github.com/ryobg/sse-gui

# Development

* All incoming or outgoing strings are UTF-8 compatible. Internally, SSEH converts these to the
  Windows Unicode when needed.
* API is not thread safe, as the rendering and input handling is done from the same thread anyway.

## Building

Required tools:
* Python 3.x for the build system (2.x may work too)
* C++14 compatible compiler available on the PATH (mingw was used so far)
* 7z and eventually the MinGW Binutils `strip` tool for the `pack` step below

Then to configure and build: 
```sh
CXX=x86_64-w64-mingw32-g++-posix ./waf configure`
./waf
./waf pack
```
Refer to file `./wscript` for the build settings.

The `-posix` suffix is used to link against the pthread implementation for threading support.
Otherwise, the default winthreads is dragging one additional DLL as dependency.

The `pack` step is to prepare a 7z archive ready for distribution. It also uses the strip tool for
removing the debug information from the DLL which apparently some compiler versions add even without
the `-g` flag.

## License

LGPLv3, see the LICENSE.md file. Modules in `share/` have their own license (e.g. CImGui and ImGui)

