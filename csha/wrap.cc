#include <string>
#include <cstdint>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <emscripten/bind.h>
#include <emscripten.h>

#include "sha-256.h"

std::string
to_hex(uint8_t* data, size_t nn)
{
    std::ostringstream tmp;
    tmp << std::setw(2) << std::setfill('0') << std::hex;
    for (int ii = 0; ii < nn; ++ii) {
        tmp << (int) data[ii];
    }
    return tmp.str();
}

EMSCRIPTEN_KEEPALIVE
std::string
sha256(std::string input)
{
    uint8_t hash[32];
    calc_sha_256(hash, (void*) input.c_str(), input.size());
    return to_hex(hash, 32);
}

EMSCRIPTEN_BINDINGS(csha) {
    emscripten::function("sha256", &sha256);
}
