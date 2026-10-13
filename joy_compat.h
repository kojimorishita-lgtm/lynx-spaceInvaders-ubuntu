#ifndef JOY_COMPAT_H
#define JOY_COMPAT_H

#include <lynx.h>

#define JOY_BTN_DOWN(v)  ((v) & JOY_DOWN_MASK)
#define JOY_BTN_UP(v)    ((v) & JOY_UP_MASK)
#define JOY_BTN_LEFT(v)  ((v) & JOY_LEFT_MASK)
#define JOY_BTN_RIGHT(v) ((v) & JOY_RIGHT_MASK)
#define JOY_BTN_FIRE(v)  ((v) & JOY_BTN_1_MASK)
#define JOY_BTN_FIRE2(v) ((v) & JOY_BTN_2_MASK)

#endif
