/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: ClangMemCpy_s.hpp
    Date: 2020-9-12
    Author: Reece
    Purpose: TBD
***/
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