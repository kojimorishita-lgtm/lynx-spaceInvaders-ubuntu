# comment
I am conducting operational tests in an Ubuntu environment, but they are not yet complete.

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


### How to Build on Ubuntu
If you are using the Ubuntu standard package (`apt install cc65`), you can build the ROM using the dedicated Makefile:

```bash
make -f Makefile_ubuntu clean
make -f Makefile_ubuntu
```
*Note: Includes a local assembly patch (`patch.o`) to bypass a known bug in the Ubuntu cc65 library package where internal runtime functions (`ldptr10sp`) are missing.*
