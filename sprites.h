
#ifndef _SPRITES
#define _SPRITES

#include <lynx.h>
#include <tgi.h>
#include <_suzy.h>

#include "consts.h"

typedef struct {
  char collindex;   // collision index
  SCB_REHV_PAL sprite; // パレット対応の正しい型
  int initx, inity; // initial position in the grid of ships
  char alive;
} sprite_t;

typedef struct {
  char collindex;   // collision index
  SCB_REHV_PAL sprite;
} sprite_pl;

typedef struct {
  char collindex;   // collision index
  SCB_REHV_PAL sprite;
} sprite_shot;

typedef struct {
  char collindex;   // collision index
  SCB_REHV_PAL sprite;
} sprite_bunker;

typedef struct {
  char collindex;   // collision index
  SCB_REHV_PAL sprite;
  void *next;
} sprite_bomb;


// function declarations:
void createEnemySprite(int i, int j, sprite_t* enemy, void* next);
void createPlayerSprite(sprite_pl* player);
void createShotSprite(sprite_shot* shot);
void createBunkerSprite(sprite_bunker* bunker, unsigned char * data);
void createBombSprite(sprite_bomb* shot);


// bunker template data:
// 0000 0011 1111 1100 0000
// 0000 1111 1111 1111 0000
// 0011 1111 1111 1111 1100
// 1111 1111 1111 1111 1111
// 1111 1111 1111 1111 1111
// 1111 1100 0000 0011 1111

extern unsigned char bunker_template[];

#endif
