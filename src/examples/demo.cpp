// Copyright (c) 2020 AlertAvert.com. All rights reserved.
// Created by M. Massenzio (marco@alertavert.com)

#include "assert.h"

#include <iostream>
#include <regex>
#include <string>
#include <glog/logging.h>

#include "version.h"
#include "BigDecimal.hpp"


using namespace std;

namespace demo {

void usage(const std::string &arg) {
  regex progname{"/?(\\w+)$"};
  smatch matches;
  string prog{arg};

  if (regex_search(arg, matches, progname)) {
    prog = matches[0];
  }
  cout << "Usage: " << prog << " value\n"
       << "\n\tWhere `value` is a large integer in hex representation"
  << endl;
}

void headline() {
  cout << "BigDecimal Project Demo - " << RELEASE_STR << endl << endl;
}
} // namespace demo

int main(int argc, char *argv[]) {
  demo::headline();
  if (argc < 2) {
    demo::usage(argv[0]);
    std::cerr << "[ERROR] Missing required argument `value`" << endl;
    exit(EXIT_FAILURE);
  }

  std::string value{argv[1]};
  ::BigDecimal s(value);

  auto conv = std::string(s);
  std::cout << conv << std::endl;
  assert(conv == value);

  return EXIT_SUCCESS;
}
