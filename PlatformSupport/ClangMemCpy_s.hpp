#pragma once

static int memcpy_s(void * dest, size_t destsz,
                  const void * src, size_t count)
{
    if (count > destsz)
    {
        return 1;
    }
    std::memcpy(dest, src, std::min(destsz, count));
    return 0;
}