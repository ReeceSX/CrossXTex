/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: DXMemory.hpp
    Date: 2020-9-12
    Author: Reece
    Purpose: TBD
***/
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
