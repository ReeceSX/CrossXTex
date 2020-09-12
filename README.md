![DirectX Logo](https://github.com/Microsoft/DirectXTex/wiki/X_jpg.jpg)

# CrossXTex
A fork of the DirectXTex library component for Mac OS and Linux


## Directory Layout

* ``DirectXTex\``

  + This contains the DirectXTex library. This includes a full-featured DDS reader and writer including legacy format conversions, a TGA reader and writer, a HDR reader and writer, an optional WIC-based bitmap reader and writer (BMP, JPEG, PNG, TIFF, and HD Photo), and various texture processing functions. This is intended primarily for tool usage.

* ``DDSTextureLoader\``

  + This contains a streamlined version of the legacy DirectX SDK sample *DDSWithoutD3DX11* texture loading code for a simple light-weight runtime DDS loader. There are versions for Direct3D 9, Direct3D 11, and Direct3D 12. This performs no runtime pixel data conversions. This is ideal for runtime usage, and supports the full complement of Direct3D texture  resources (1D, 2D, volume maps, cubemaps, mipmap levels, texture arrays, BC formats, etc.).

* ``WICTextureLoader\``

  + This contains a Direct3D 9, Direct3D 11 and Direct3D 12 2D texture loader that uses WIC to load a bitmap (BMP, JPEG, PNG, HD Photo, or other WIC supported file container), resize if needed based on the current feature level (or by explicit parameter), format convert to a DXGI_FORMAT if required, and then create a 2D texture. Note this does not support 1D textures, volume textures, cubemaps, or texture arrays. DDSTextureLoader is recommended for fully "precooked" textures for maximum performance and image quality, but this loader can be useful for creating simple 2D texture from standard image files at runtime.

> DDSTextureLoader11, ScreenGrab11, and WICTextureLoader11 are 'stand-alone' versions of the same modules provided in the [DirectX Tool Kit for DX11](https://github.com/Microsoft/DirectXTK)

> DDSTextureLoader12, ScreenGrab12, and WICTextureLoader12 are 'stand-alone' versions of the same modules provided in the [DirectX Tool Kit for DX12](https://github.com/Microsoft/DirectXTK12).

# Documentation

Documentation is available on the [GitHub wiki](https://github.com/Microsoft/DirectXTex/wiki).

## Notices

All content and source code for this package are subject to the terms of the [MIT License](http://opensource.org/licenses/MIT).

Checkout the original [repository](https://github.com/microsoft/DirectXTex). for the latest build

Copyright (c) Microsoft Corporation. All rights reserved.