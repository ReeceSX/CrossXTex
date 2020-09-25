#pragma once

enum WICBitmapTransformOptions
{
    /// <summary>
    /// Don't Rotate
    /// </summary>
    WICBitmapTransformRotate0                = 0,
    /// <summary>
    /// Rotate 90 degree clockwise
    /// </summary>
    WICBitmapTransformRotate90            = 0x1,
    /// <summary>
    /// Rotate 180 degree
    /// </summary>
    WICBitmapTransformRotate180           = 0x2,
    /// <summary>
    /// Rotate 270 degree clockwise
    /// </summary>
    WICBitmapTransformRotate270           = 0x3,
    /// <summary>
    /// Flip the image horizontally
    /// </summary>
    WICBitmapTransformFlipHorizontal      = 0x8,
    /// <summary>
    /// Flip the image vertically
    /// </summary>
    WICBitmapTransformFlipVertical        = 0x10
};