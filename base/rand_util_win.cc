// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#define _CRT_RAND_S

#include "base/rand_util.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "base/basictypes.h"
#include "base/logging.h"

namespace {

uint32 RandUint32() {
  uint32 number;
  CHECK_EQ(rand_s(&number), 0);
  return number;
}

}  // namespace

namespace base {

// NOTE: This function must be cryptographically secure. http://crbug.com/140076
uint64 RandUint64() {
  uint32 first_half = RandUint32();
  uint32 second_half = RandUint32();
  return (static_cast<uint64>(first_half) << 32) + second_half;
}

}  // namespace base
