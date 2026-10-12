#include <string.h>  // memcpy のために追加
#include "sprites.h"

unsigned char singlepixel_data[] = { 0x03, 0x87, 0x80, 0x00 };

unsigned char bunker_template[] = {
	0x04, 0x03, 0xfc, 0x00,
	0x04, 0x0f, 0xff, 0x00,
	0x04, 0x3f, 0xff, 0xc0,
	0x04, 0xff, 0xff, 0xf0,
	0x04, 0xff, 0xff, 0xf0,
	0x04, 0xfc, 0x03, 0xf0,
	0x00
};

void createBunkerSprite(sprite_bunker* bunker, unsigned char * data){
    bunker->sprite.sprctl0 = BPP_1 | TYPE_NORMAL;
    bunker->sprite.sprctl1 = REHV | LITERAL;
    bunker->sprite.sprcoll = 4;

    bunker->sprite.hsize = 0x0100;
    bunker->sprite.vsize = 0x0100;

    bunker->sprite.data = data;
    
    // ポインタへのループ代入を memcpy に変更し、ldptr10sp の発生を完全に防ぎます
    memcpy(data, bunker_template, BUNKER_DATA_LEN);
}

void createEnemySprite(int i, int j, sprite_t* sprite, void* next){
    sprite->sprite.sprctl0 = BPP_1 | TYPE_NORMAL;
    sprite->sprite.sprctl1 = REHV;
    
    switch(i % 3){
        case 0:  sprite->sprite.sprcoll = 1; break;
        case 1:  sprite->sprite.sprcoll = 2; break;
        case 2:  sprite->sprite.sprcoll = 3; break;
        default: sprite->sprite.sprcoll = 4; break;
    }
    
    sprite->sprite.data = singlepixel_data;
    sprite->sprite.next = next;
    sprite->sprite.hsize = 0x0100 * SHIPWIDTH;
    sprite->sprite.vsize = 0x0100 * SHIPHEIGHT;
    sprite->initx = j * (SHIPWIDTH + SINV_SHIPGAPX);
    sprite->inity = i * (SHIPHEIGHT + SINV_SHIPGAPY);
    sprite->alive = 1;
}

void createPlayerSprite(sprite_pl* player){
    player->sprite.sprctl0 = BPP_1 | TYPE_NORMAL;
    player->sprite.sprctl1 = REHV;
    player->sprite.sprcoll = 5;
    player->sprite.data = singlepixel_data;
    player->sprite.hsize = 0x0100 * PLAYER_SPRITE_WIDTH;
    player->sprite.vsize = 0x0100 * PLAYER_SPRITE_HEIGHT;
}

void createShotSprite(sprite_shot* shot){
    shot->sprite.sprctl0 = BPP_1 | TYPE_NORMAL;
    shot->sprite.sprctl1 = REHV;
    shot->sprite.sprcoll = 2;
    shot->sprite.data = singlepixel_data;
    shot->sprite.hsize = 0x0100;
    shot->sprite.vsize = 0x0100 * SHOT_SPRITE_HEIGHT;
}

void createBombSprite(sprite_bomb* shot){
    shot->sprite.sprctl0 = BPP_1 | TYPE_NORMAL;
    shot->sprite.sprctl1 = REHV;
    shot->sprite.sprcoll = 6;
    shot->sprite.data = singlepixel_data;
    shot->sprite.hsize = 0x0100;
    shot->sprite.vsize = 0x0100 * BOMB_SPRITE_HEIGHT;
}

