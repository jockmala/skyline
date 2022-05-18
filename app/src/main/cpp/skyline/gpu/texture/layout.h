// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include "texture.h"

namespace skyline::gpu::texture {
    // Reference on Block-linear tiling: https://gist.github.com/PixelyIon/d9c35050af0ef5690566ca9f0965bc32
    constexpr u8 SectorWidth{16}; // The width of a sector in bytes
    constexpr u8 SectorHeight{2}; // The height of a sector in lines
    constexpr u8 GobWidth{64}; // The width of a GOB in bytes
    constexpr u8 GobHeight{8}; // The height of a GOB in lines

    /**
     * @return The size of a layer of the specified non-mipmapped block-slinear surface in bytes
     */
    size_t GetBlockLinearLayerSize(Dimensions dimensions,
                                   size_t formatBlockWidth, size_t formatBlockHeight, size_t formatBpb,
                                   size_t gobBlockHeight, size_t gobBlockDepth);

    /**
     * @brief Copies the contents of a blocklinear texture to a linear output buffer
     */
    void CopyBlockLinearToLinear(Dimensions dimensions,
                                 size_t formatBlockWidth, size_t formatBlockHeight, size_t formatBpb,
                                 size_t gobBlockHeight, size_t gobBlockDepth,
                                 u8 *guestInput, u8 *linearOutput);

    /**
     * @brief Copies the contents of a blocklinear guest texture to a linear output buffer
     */
    void CopyBlockLinearToLinear(const GuestTexture &guest, u8 *guestInput, u8 *linearOutput);

    /**
     * @brief Copies the contents of a blocklinear texture to a linear output buffer
     */
    void CopyLinearToBlockLinear(Dimensions dimensions,
                                 size_t formatBlockWidth, size_t formatBlockHeight, size_t formatBpb,
                                 size_t gobBlockHeight, size_t gobBlockDepth,
                                 u8 *linearInput, u8 *guestOutput);

    /**
     * @brief Copies the contents of a blocklinear guest texture to a linear output buffer
     */
    void CopyLinearToBlockLinear(const GuestTexture &guest, u8 *linearInput, u8 *guestOutput);

    /**
     * @brief Copies the contents of a pitch-linear guest texture to a linear output buffer
     * @note This does not support 3D textures
     */
    void CopyPitchLinearToLinear(const GuestTexture &guest, u8 *guestInput, u8 *linearOutput);

    /**
     * @brief Copies the contents of a linear buffer to a pitch-linear guest texture
     * @note This does not support 3D textures
     */
    void CopyLinearToPitchLinear(const GuestTexture &guest, u8 *linearInput, u8 *guestOutput);
}
