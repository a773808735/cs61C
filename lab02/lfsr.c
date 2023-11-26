#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg)
{
    unsigned cur = *reg;
    unsigned res = 0x01;
    res &= cur;
    cur = cur >> 2;
    res ^= cur;
    cur = cur >> 1;
    res ^= cur;
    cur = cur >> 2;
    res ^= cur;
    res &= 0x01;
    *reg = *reg >> 1;
    if (res == 1)
    {
        *reg |= (1U << 15);
    }
    else
    {
        *reg &= ~(1U << 15);
    }
}
