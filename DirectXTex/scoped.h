//-------------------------------------------------------------------------------------
// scoped.h
//  
// Utility header with helper classes for exception-safe handling of resources
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//-------------------------------------------------------------------------------------

#pragma once


//---------------------------------------------------------------------------------
struct aligned_deleter { void operator()(void* p) noexcept { std::free(p); } };

using ScopedAlignedArrayFloat = std::unique_ptr<float[], aligned_deleter>;

using ScopedAlignedArrayXMVECTOR = std::unique_ptr<DirectX::XMVECTOR[], aligned_deleter>;


static inline void * AllocateVectorAligned(size_t length)
{
    return std::aligned_alloc(16, length);
}