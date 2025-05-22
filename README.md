# Dr. Robotnik's Ring Racers

<p align="center">
  <a href="https://www.kartkrew.org">
    <img src="docs/logo.png" width="404" style="image-rendering:pixelated" alt="Dr. Robotnik's Ring Racers logo">
  </a>
</p>

Dr. Robotnik's Ring Racers is a kart racing video game originally based on the 3D Sonic the Hedgehog fangame [Sonic Robo Blast 2](https://srb2.org/), itself based on a modified version of [Doom Legacy](http://doomlegacy.sourceforge.net/).

Ring Racers' source code is available to users under the GNU General Public License version 2.0 or higher.

## Links

- [Kart Krew Dev Website](https://www.kartkrew.org/)
- [Kart Krew Dev Discord](https://www.kartkrew.org/discord)
- [SRB2 Forums](https://mb.srb2.org/)

## Disclaimer

Dr. Robotnik's Ring Racers is a work of fan art made available for free without intent to profit or harm the intellectual property rights of the original works it is based on. Kart Krew Dev is in no way affiliated with SEGA Corporation. We do not claim ownership of any of SEGA's intellectual property used in Dr. Robotnik's Ring Racers.

# Development

## Building from Source

Ring Racers is built using a compatible C++ toolchain (GCC, MinGW, Clang and Apple Clang as of this writing), CMake, and Microsoft vcpkg. The compiler and runtime libraries must support the ISO C++17 standard and ISO C11 standard.

On Linux platforms, you will need the following libraries available on the system.

- libcurl
- zlib
- libpng
- libogg
- libvorbis
- libvpx
- libyuv
- SDL2

On Windows and macOS, you will need to install [vcpkg] instead to build these dependencies alongside the game.

[vcpkg]: https://vcpkg.io/en/

To configure and build the game, there are [CMake presets] (declared in `CMakePresets.json`). These presets require the ninja build script tool in addition to cmake and your C++ toolchain. Here is a non-exhaustive list of them:

- ninja-debug: non-optimized, assertions enabled
- ninja-develop: optimized, assertions enabled
- ninja-release: optimized
- ninja-x86_mingw_static_vcpkg-debug
- ninja-x86_mingw_static_vcpkg-develop
- ninja-x86_mingw_static_vcpkg-release
- ninja-x64_osx_vcpkg-debug
- ninja-x64_osx_vcpkg-develop
- ninja-x64_osx_vcpkg-release
- ninja-arm64_osx_vcpkg-debug
- ninja-arm64_osx_vcpkg-develop
- ninja-arm64_osx_vcpkg-release

[CMake presets]: https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html

These presets depend on the `VCPKG_ROOT` environment variable being specified before the first run of the `cmake` command. Their build directories are pre-configured as subdirectories of `build/`.

After all prerequisites are set-up, configure and build using the following commands, adjusting according to your target system:

    cmake --preset ninja-x86_mingw_static_vcpkg-develop
    cmake --build --preset ninja-x86_mingw_static_vcpkg-develop

## Contributing

We welcome external contributions from the community. If you are planning on making a large feature you intend to contribute to the project, please consider reaching out to us in the Kart Krew Dev public Discord server so we can coordinate with you.

Our primary source repository is [hosted on the SRB2 Gitlab](https://git.do.srb2.org/KartKrew/RingRacers). The Github repository is a mirror of this. If you submit a Pull Request to the Github repository, please keep in mind that we do not consistently monitor that mirror and may not see your request.

All contributions must be made available under the GPL General Public License version 2.0, or public domain. Integrations for third party code must be made to code which is compatibly licensed.

## Notice/explanation
This repository is not the original ring racers repository, it's a fork and is a attempt at making P_SKIN's from ring racers behave like regular Legacy Doom's S_SKIN, Doom's S_SKIN replaces Doomguy's sprites instead of treating the S_SKIN as a separate character/racer. S_SKIN's are know as skins in doom source ports and allow the player to have a custom appearence with doomguy without patching the actual games graphics with a wad. S_SKIN in ring racers do patch the game and treat the skin separately instead of replacing graphics. This was probably done to incorporate lua and soc into racers so they would be more customizable in terms of code. P_SKIN's are like doom's S_SKIN but as the P implies, it patches characters, the way they work is that they use the name of the character your trying to patch, names in ring racers seem to be used internally and only the realname seems to be used. Try it yourself by replacing the S in a character wad with a P and replace the name in the lump to a character of your choice. P_SKIN is not really common for racers except maybe full conversion addons or gamebanana trash, but they do have potential of being used online like doom skins. This is for more better customization with characters like having outfits, complete character reskins. But all would be possible online, since character wads are small in size it wouldn't be that tricky since wads are designed to have small file sizes. With the only problem being sounds since they are the biggest. Of course I decided to make limitations of online play into account and thought maybe people could use sounds in the doom sound format. I also think of maybe adding a blank .ogg to the games files in case of silent characters with some code that makes it so if characters have silent set to them, they can use that blank sfx instead of having it in the wad (Applies to S_SKIN and P_SKIN) and maybe make a fork of kartmaker for this. This is all an idea I had and I don't know C at all yet but plan on making some tests with both Doom Legacy and Ring Racers.
