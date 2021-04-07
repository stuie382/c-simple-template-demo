#pragma once

#include <stdint.h>
// Added in case the project gets compiled as C++.
#ifdef __cplusplus
extern "C" {
#endif

struct bowling;

struct bowling *bowling_init(void);

void bowling_free(struct bowling *b);

void roll_ball(struct bowling *b, int n);

int score_game(struct bowling *b);

#ifdef __cplusplus
}
#endif
