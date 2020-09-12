/***
    Copyright (�) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: Win32Public.hpp
    Date: 2020-9-12
    Author: Reece
    Purpose: TBD
***/
 #pragma once

#if !defined(__cdecl)
    #define __cdecl
#endif 

#if defined(_DXTX_NOWIN)
    using LONG = size_t;
    using HANDLE = size_t;
    using WORD = int16_t;
    using DWORD = uint32_t;
    using UINT = uint32_t;
    using INT = int32_t;
    
    #include "Win32DXG.hpp"
    #include "Win32Errors.hpp"
    #include "Win32WIC.hpp"
#endif