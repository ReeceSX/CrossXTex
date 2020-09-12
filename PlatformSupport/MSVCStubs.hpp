#include <cstdint>

#define __cdecl

typedef struct _GUID {
  unsigned long  Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned char  Data4[8];
} GUID;

typedef size_t HANDLE;

#define UNREFERENCED_PARAMETER

#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
extern "C++" { \
inline ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) | ((int)b)); } \
inline ENUMTYPE &operator |= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) |= ((int)b)); } \
inline ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) & ((int)b)); } \
inline ENUMTYPE &operator &= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) &= ((int)b)); } \
inline ENUMTYPE operator ~ (ENUMTYPE a) { return ENUMTYPE(~((int)a)); } \
inline ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) ^ ((int)b)); } \
inline ENUMTYPE &operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) ^= ((int)b)); } \
}

#define ARRAYSIZE(a) \
  ((sizeof(a) / sizeof(*(a))) / \
  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

#define _countof(array) (sizeof(array) / sizeof(array[0]))

#include "MSVCSal.h"

#include <stdbool.h>

#define BOOL int
#define TRUE 1
#define FALSE 0


     enum WICBitmapTransformOptions
    {
        /// <summary>
        /// Don't Rotate
        /// </summary>
        WICBitmapTransformRotate0                = 0,
        /// <summary>
        /// Rotate 90 degree clockwise
        /// </summary>
        WICBitmapTransformRotate90            = 0x1,
        /// <summary>
        /// Rotate 180 degree
        /// </summary>
        WICBitmapTransformRotate180           = 0x2,
        /// <summary>
        /// Rotate 270 degree clockwise
        /// </summary>
        WICBitmapTransformRotate270           = 0x3,
        /// <summary>
        /// Flip the image horizontally
        /// </summary>
        WICBitmapTransformFlipHorizontal      = 0x8,
        /// <summary>
        /// Flip the image vertically
        /// </summary>
        WICBitmapTransformFlipVertical        = 0x10
    };