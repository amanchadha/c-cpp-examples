#include <stdio.h>
#include <stdint.h>

typedef union
{
    struct
    {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
    };
    uint32_t x;
} somenewtype;

typedef union
{
    uint32_t* p;
    uint8_t* q;
} somepointer;

int main(int argc, char** argv)
{
    union ARGB
    {
        uint32_t colour;
    
        struct componentsTag
        {
            uint8_t b;
            uint8_t g;
            uint8_t r;
            uint8_t a;
        } components;
    
    } pixel;
    
    pixel.colour = 0xff040201;  // ARGB::colour is the active member from now on
    
    // somewhere down the line, without any edit to pixel
    
    printf("%x\n", pixel.components.a);      // accessing the non-active member ARGB::components

    uint32_t r;
    uint8_t s;
    somenewtype z;
    somepointer p;
    r = 0x11223344; s = 0x11;
    z.x = 0x11223344;
    p.p = &r;
    p.q = &s;
    printf("%x%x%x%x\n", z.d, z.c, z.b, z.a);
    printf("%x %x\n", *(p.p), *(p.q));
}
