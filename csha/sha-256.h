#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>

void calc_sha_256(uint8_t* hash, const void *input, size_t len);

#endif
