// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_BASE64_H__
#define BASE_BASE64_H__

#include <string>

#include "base/base_export.h"
#include "base/string_piece.h"

namespace base {

// Encodes the input string in base64.  Returns true if successful and false
// otherwise.  The output string is only modified if successful.
BASE_EXPORT bool Base64Encode(const StringPiece& input, char* output, size_t* encodeLength);

// Decodes the base64 input string.  Returns true if successful and false
// otherwise.  The output string is only modified if successful.
BASE_EXPORT bool Base64Decode(const StringPiece& input, char* output, size_t* decodeLength);

// Return encode/decode string length, In case finally length is more than [modp_b64_encode_len] 10b.
BASE_EXPORT size_t Base64EncodeLength(const StringPiece& input);
BASE_EXPORT size_t Base64DecodeLength(const StringPiece& input);

}  // namespace base

#endif  // BASE_BASE64_H__
