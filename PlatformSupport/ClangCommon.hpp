#pragma once

#include "ClangBsearch.hpp"

static int memcpy_s(void * dest, size_t destsz,
                  const void * src, size_t count)
{
    size_t minVal = std::min(destsz, count);
    if (count > destsz)
    {
        return 1;
    }
    std::memcpy(dest, src, minVal);
    return 0;
}
