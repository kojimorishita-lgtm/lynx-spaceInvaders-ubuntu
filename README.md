# lynx-spaceInvaders
Space Invaders game for Atari Lynx

Steps:
* Sprite rendering (done)
* Joystick input handling (done)
* Movable grid of ship sprites (done)
* Moveable player sprite (done)
* Shot and bomb sprites
* Collision detection (done)
* Adjustable timer to move the ships
* Shot destroying a ship (done), bomb destroying player
* Game model 
  * timer adjustments
  * ship descent
  * player lives
* Bunkers - rendering, destroyable
* Mystery ship
* Game tuning - size of ships, player, bunkers, gaps, speed of shot, speed of player, timer adjustment, etc.
* Sound - in sync with the ship movement
* Sprites - alternating ship drawings, nice player drawing
* Intro screen
* High score screen

Testing mobile development

# Space Invaders for Atari Lynx — Ubuntu build

This project builds the Atari Lynx Space Invaders source using the **Ubuntu-distributed cc65** toolchain. The original Windows-oriented build files are retained.

## Tested environment

- Ubuntu 26.04.1 LTS under WSL
- Ubuntu `cc65` package `2.19-2build1` (compiler reports V2.18)
- GNU Make
- Handy emulator on Windows

## Install dependencies

```sh
sudo apt update
sudo apt install cc65 make
```

The Ubuntu build uses tools from `/usr/bin` and support files from `/usr/share/cc65`. This layout is specific to the Ubuntu package and may differ on other distributions or source installations.

## Build

From the project directory:

```sh
make -f Makefile_ubuntu
```

This produces `spaceInv.lnx`. To remove generated build files:

```sh
make -f Makefile_ubuntu clean
```

## Run with Handy

Copy `spaceInv.lnx` from WSL to a Windows directory, then open it in the Handy Atari Lynx emulator. For example:

```sh
cp spaceInv.lnx /mnt/c/Users/YOUR_WINDOWS_USER/Downloads/
```

Replace `YOUR_WINDOWS_USER` with your Windows username.

## Porting changes

- Added `Makefile_ubuntu` with paths for Ubuntu's cc65 package and Lynx JOY/TGI drivers.
- Added `joy_compat.h` to provide joystick input macros used by the game.
- Changed `bunker_template` to a single definition in `sprites.c`, with an `extern` declaration in `sprites.h`.
- Used the packaged `lynx-coll.cfg` linker configuration, as in the original build.

## Verified behavior and known limitations

Confirmed in Handy: ROM startup, screen display, enemy movement, player left/right movement, shooting, and enemy hit/removal. Enemy and player graphics are simple rectangles in the current source. Bunker hit/damage handling is not implemented. A compiler warning about an unused `bunker` parameter remains.

These are observations of this port, not a claim that all game behavior is fully tested.

## License and attribution

The original project is Copyright (c) 2018 Marek Kukacka and is licensed under the MIT License. See `LICENSE` for the full text. Retain that notice and license when redistributing this project.

# comment
I am conducting operational tests in an Ubuntu environment, but they are not yet complete.
