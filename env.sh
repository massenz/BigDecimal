#!/bin/bash
#
# This file (c) 2020 AlertAvert.com.  All rights reserved.

BASEDIR="$(abspath $(dirname $0)/..)"
BUILDDIR="${BASEDIR}/build"
CLANG=$(which clang++)
UTILS="-DCOMMON_UTILS_DIR=${UTILS_DIR}"

OS_NAME=$(uname -s)
if [[ ${OS_NAME} == "Linux" ]]; then
  export LD_LIBRARY_PATH="${BUILDDIR}/lib":${LD_LIBRARY_PATH:-}
elif [[ ${OS_NAME} == "Darwin" ]]; then
  export DYLD_LIBRARY_PATH="${BUILDDIR}/lib":${DYLD_LIBRARY_PATH:-}
else
    echo "[ERROR] Unsupported Linux variant: ${OS_NAME}"
    exit 1
fi
