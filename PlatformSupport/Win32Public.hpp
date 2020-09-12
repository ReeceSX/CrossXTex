 #pragma once

#if defined(_DXTX_NOWIN)
    using LONG = size_t;
    #include "Win32DXG.hpp"
    #include "Win32Errors.hpp"
    #include "Win32WIC.hpp"
#endif