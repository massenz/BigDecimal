// Copyright (c) 2016 AlertAvert.com. All rights reserved.
// Created by M. Massenzio (marco@alertavert.com) on 3/6/16.

#pragma once

#include <cmath>
#include <iomanip>
#include <string>
#include <glog/logging.h>
#include <functional>

namespace {

 class not_implemented : public std::exception {
   std::string reason_;
  public:
   explicit not_implemented(const std::string& reason) : reason_(reason) {}

   const char* what() const noexcept override {
     return reason_.c_str();
   }
 };

 class bad_hex : public std::exception {
   std::string reason_;
  public:
   explicit bad_hex(const std::string& reason) : reason_(reason) {}

   const char* what() const noexcept override {
     return reason_.c_str();
   }
 };

const short NUM_ = 4;
const short DIGITS_ = 16;
const unsigned long long DIV_ = 1L << 63;

// Implements a 256-bit unsigned integer (uint256)
class BigDecimal {
 private:
  unsigned long long b[NUM_];

 public:
  explicit BigDecimal(const std::string& hex) {
    if (hex.find_first_of("0x") != 0) {
      throw bad_hex{"Missing leading `0x`"};
    }
    auto digits = hex.substr(2);
    int i = 0;
    int start, count;

    while (digits.length() > 0) {
      if (digits.length() >= DIGITS_) {
        start = digits.length() - DIGITS_;
        count = DIGITS_;
      } else {
        start = 0;
        count = digits.length();
      }

      std::stringstream ss;
      ss << std::hex << digits.substr(start, count);
      ss >> b[i++];

      digits = digits.substr(0, digits.length() - count);
    }
  };

  explicit operator std::string() const {
    std::stringstream buf;
    buf << "0x" << std::hex << std::setw(16) << std::setfill('0');
    for (int i = NUM_; i > 0; --i) {
      buf << b[i-1];
    }
    return buf.str();
  }
};
}
