#pragma once

#include <cinttypes>

using HRESULT = LONG;
using WORD = int16_t;
using DWORD = uint32_t;
using UINT = uint32_t;
using INT = int32_t;

#define FACILITY_WIN32      7

#define SEVERITY_SUCCESS    0
#define SEVERITY_ERROR      1

#define __HRESULT_FROM_WIN32(x) ((HRESULT)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))
#define HRESULT_FROM_WIN32(x) __HRESULT_FROM_WIN32(x)

#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define IS_ERROR(Status) (((unsigned long)(Status)) >> 31 == SEVERITY_ERROR)

#define S_OK            ((HRESULT)0)
#define S_FALSE         ((HRESULT)1L)
#define E_UNEXPECTED    ((HRESULT)(0x8000FFFFL))
#define E_NOTIMPL       ((HRESULT)(0x80004001L))
#define E_OUTOFMEMORY   ((HRESULT)(0x8007000EL))
#define E_INVALIDARG    ((HRESULT)(0x80070057L))
#define E_NOINTERFACE   ((HRESULT)(0x80004002L))
#define E_POINTER       ((HRESULT)(0x80004003L))
#define E_HANDLE        ((HRESULT)(0x80070006L))
#define E_ABORT         ((HRESULT)(0x80004004L))
#define E_FAIL          ((HRESULT)(0x80004005L))
#define E_ACCESSDENIED  ((HRESULT)(0x80070005L))
#define E_PENDING       ((HRESULT)(0x8000000AL))

 #define ERROR_ACCESS_DENIED          5
 #define ERROR_INVALID_HANDLE         6
 #define ERROR_OUTOFMEMORY           14
 #define ERROR_NOT_SUPPORTED         50
 #define ERROR_INVALID_PARAMETER     87
 #define ERROR_CALL_NOT_IMPLEMENTED 120
 #define ERROR_INVALID_NAME         123
 #define ERROR_MOD_NOT_FOUND        126
 #define ERROR_NO_MORE_ITEMS        259
 #define ERROR_INVALID_ADDRESS      487

 #define ERROR_ARITHMETIC_OVERFLOW  534


#define ERROR_SUCCESS                                      0
#define ERROR_INVALID_FUNCTION                             1
#define ERROR_FILE_NOT_FOUND                               2
#define ERROR_PATH_NOT_FOUND                               3
#define ERROR_TOO_MANY_OPEN_FILES                          4
#define ERROR_ACCESS_DENIED                                5
#define ERROR_INVALID_HANDLE                               6
#define ERROR_ARENA_TRASHED                                7
#define ERROR_NOT_ENOUGH_MEMORY                            8
#define ERROR_INVALID_BLOCK                                9
#define ERROR_BAD_ENVIRONMENT                              10
#define ERROR_BAD_FORMAT                                   11
#define ERROR_INVALID_ACCESS                               12
#define ERROR_INVALID_DATA                                 13
#define ERROR_OUTOFMEMORY                                  14

#define ERROR_FILE_EXISTS                                  80
#define ERROR_CANNOT_MAKE                                  82

#define ERROR_INSUFFICIENT_BUFFER                          122
#define ERROR_INVALID_STATE                                5023
#define ERROR_FILE_TOO_LARGE                               223
#define ERROR_HANDLE_EOF                                   38
#define ERROR_FILE_TOO_LARGE                               223

#define E_NOT_SUFFICIENT_BUFFER                            HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
#define E_NOT_VALID_STATE                                  HRESULT_FROM_WIN32(ERROR_INVALID_STATE)