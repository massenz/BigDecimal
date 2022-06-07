// Copyright (c) 2016 AlertAvert.com. All rights reserved.
// Created by M. Massenzio (marco@alertavert.com) on 3/6/16.

#pragma once

#include <cmath>
#include <string>
#include <glog/logging.h>

namespace {

const short NUM_ = 4;
const float DIV_ = 2e+64;

// Implements a 256-bit unsigned integer (uint256)
class BigDecimal {
 private:
  uint64_t b[NUM_];

 public:
  explicit BigDecimal(uint64_t value) {
    for (int i = 0; i < NUM_; ++i) {
      b[i] = 0;
    }
    b[0] = value;
  };

  // A 256-bit unsigned integer can represent approximately up to 10^+79
  // thus a float has enough range to represent it; the decimal part will
  // be ignored.
  // Also, due to rounding divisions while converting to binary representation,
  // the actual resulting value may be off by one.
  explicit BigDecimal(float val) {
    // TODO: Implement logic here
    val = std::floor(val);
    for (unsigned long & i : b) {
      float r = std::fmod(val, DIV_);
      i = std::floor(r);
      val = std::floor(val / DIV_);
      if (val < 1.0) break;
    }
  }

  explicit operator std::string() const {
    // TODO: Implement logic here
    return std::to_string(b[0]);
  }
};
}
