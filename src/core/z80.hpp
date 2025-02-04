#ifndef Z80_HPP_
#define Z80_HPP_

#include "typedef.hpp"
#include "bit.hpp"

#define R(pair) \
    union { reg_pair _8; u16 _16; } pair

#define GET(reg_l, reg_h, pair) \
    constexpr u8& reg_l() { return _##pair._8.l; }; \
    constexpr u8& reg_h() { return _##pair._8.h; }; \
    constexpr u16& pair() { return _##pair._16; }

#define SET(reg_l, reg_h, pair) \
    constexpr void reg_l(u8 value) { _##pair._8.l = value; }; \
    constexpr void reg_h(u8 value) { _##pair._8.h = value; }; \
    constexpr void pair(u16 value) { _##pair._16 = value; }

class z80_state {
private:
    struct reg_pair { u8 l, h; };

    R(_af); R(_bc); R(_de); R(_hl); R(_ix); R(_iy); R(_sp); R(_pc);

public:
    GET(a, f, af);
    constexpr u8& psw() { return _af._8.l; };
    GET(b, c, bc);
    GET(d, e, de);
    GET(h, l, hl);
    
    SET(a, f, af);
    constexpr void psw(u8 value) { _af._8.l = value; };
    SET(b, c, bc);
    SET(d, e, de);
    SET(h, l, hl);
};

#endif