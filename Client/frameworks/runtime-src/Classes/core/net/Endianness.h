//
//  Endianness.h
//  Client
//
//  Created by barton on 16/8/23.
//
//

#ifndef Endianness_h
#define Endianness_h

//--------------
#define OFX_LITTLE_ENDIAN

// for windows
typedef unsigned char			uint8_t;
typedef signed char           	int8_t;
typedef unsigned short       	uint16_t;
typedef signed short       		int16_t;
typedef unsigned int			uint32_t;
typedef signed int				int32_t;
typedef unsigned long long   	uint64_t;


static inline uint16_t EndianSwap16(uint16_t value)
{
    return (uint16_t)((value >> 8) | (value << 8));
}

static inline int32_t EndianSwap32(int32_t value)
{
    return (((value & 0x000000ff) << 24) |
            ((value & 0x0000ff00) <<  8) |
            ((value & 0x00ff0000) >>  8) |
            ((value & 0xff000000) >> 24));
}

static inline uint64_t EndianSwap64(uint64_t value)
{
    return (((value & 0x00000000000000ffLL) << 56) |
            ((value & 0x000000000000ff00LL) << 40) |
            ((value & 0x0000000000ff0000LL) << 24) |
            ((value & 0x00000000ff000000LL) << 8)  |
            ((value & 0x000000ff00000000LL) >> 8)  |
            ((value & 0x0000ff0000000000LL) >> 24) |
            ((value & 0x00ff000000000000LL) >> 40) |
            ((value & 0xff00000000000000LL) >> 56));
}

#ifdef OFX_LITTLE_ENDIAN
#define ToBE16(n) EndianSwap16(n)
#define ToBE32(n) EndianSwap32(n)
#define ToBE64(n) EndianSwap64(n)
#define ToLE16(n) (n)
#define ToLE32(n) (n)
#define ToLE64(n) (n)
#define FromBE16(n) EndianSwap16(n)
#define FromBE32(n) EndianSwap32(n)
#define FromBE64(n) EndianSwap64(n)
#define FromLE16(n) (n)
#define FromLE32(n) (n)
#define FromLE64(n) (n)
#else  // OFX_LITTLE_ENDIAN
#define ToBE16(n) (n)
#define ToBE32(n) (n)
#define ToBE64(n) (n)
#define ToLE16(n) EndianSwap16(n)
#define ToLE32(n) EndianSwap32(n)
#define ToLE64(n) EndianSwap64(n)
#define FromBE16(n) (n)
#define FromBE32(n) (n)
#define FromBE64(n) (n)
#define FromLE16(n) EndianSwap16(n)
#define FromLE32(n) EndianSwap32(n)
#define FromLE64(n) EndianSwap64(n)
#endif

#endif /* Endianness_h */
