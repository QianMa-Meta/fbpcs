/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "fbpcf/frontend/mpcGame.h"

namespace pcf2_attribution {

const int kMaxConcurrency = 16;
const size_t timeStampWidth = 32;
const size_t originalTargetIdWidth = 64;
const size_t targetIdWidth = 16;
const size_t actionTypeWidth = 16;

template <int schedulerId, bool usingBatch = true>
using PubBit =
    typename fbpcf::frontend::MpcGame<schedulerId>::template PubBit<usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecBit =
    typename fbpcf::frontend::MpcGame<schedulerId>::template SecBit<usingBatch>;

template <int schedulerId, bool usingBatch = true>
using PubTimestamp = typename fbpcf::frontend::MpcGame<
    schedulerId>::template PubUnsignedInt<timeStampWidth, usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecTimestamp = typename fbpcf::frontend::MpcGame<
    schedulerId>::template SecUnsignedInt<timeStampWidth, usingBatch>;

template <int schedulerId, bool usingBatch = true>
using PubTargetId = typename fbpcf::frontend::MpcGame<
    schedulerId>::template PubUnsignedInt<targetIdWidth, usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecTargetId = typename fbpcf::frontend::MpcGame<
    schedulerId>::template SecUnsignedInt<targetIdWidth, usingBatch>;

template <int schedulerId, bool usingBatch = true>
using PubOriginalTargetId = typename fbpcf::frontend::MpcGame<
    schedulerId>::template PubUnsignedInt<originalTargetIdWidth, usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecOriginalTargetId = typename fbpcf::frontend::MpcGame<
    schedulerId>::template SecUnsignedInt<originalTargetIdWidth, usingBatch>;

template <int schedulerId, bool usingBatch = true>
using PubActionType = typename fbpcf::frontend::MpcGame<
    schedulerId>::template PubUnsignedInt<actionTypeWidth, usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecActionType = typename fbpcf::frontend::MpcGame<
    schedulerId>::template SecUnsignedInt<actionTypeWidth, usingBatch>;

template <typename T, bool useVector>
using ConditionalVector =
    typename std::conditional<useVector, std::vector<T>, T>::type;

template <int schedulerId, bool usingBatch = true>
using SecBitT = ConditionalVector<SecBit<schedulerId, usingBatch>, !usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecTimestampT =
    ConditionalVector<SecTimestamp<schedulerId, usingBatch>, !usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecTargetIdT =
    ConditionalVector<SecTargetId<schedulerId, usingBatch>, !usingBatch>;
template <int schedulerId, bool usingBatch = true>
using SecActionTypeT =
    ConditionalVector<SecActionType<schedulerId, usingBatch>, !usingBatch>;

} // namespace pcf2_attribution
