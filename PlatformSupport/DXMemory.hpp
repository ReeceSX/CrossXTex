#pragma once

static inline void FreeVectorAligned(void * ptr)
{
#if defined(WIN32)
    _aligned_free(ptr);
#else
    std::free(ptr);
#endif
}

static inline void * AllocateVectorAligned(size_t length)
{
#if defined(WIN32)
    return _aligned_malloc(length, 16);
#else
    return std::aligned_alloc(16, length);
#endif
}
