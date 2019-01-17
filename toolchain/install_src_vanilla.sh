#!/bin/bash

cppdock install_src e90d44039a60317e8379232d5c43dc06cef8f463 \
                    llvm-mirror/llvm      ./llvm
cppdock install_src 1d9326169cac55873d049440a9c554307c918972 \
                    ricejasonf/clang      ./llvm/tools/clang
cppdock install_src 61b0a0088b54793b2d4e7fc2f1b1a1f3893293a8 \
                    llvm-mirror/libcxx    ./llvm/projects/libcxx
cppdock install_src bd80f6625dec55d43bab409ab0b71b94472eff28 \
                    llvm-mirror/libcxxabi ./llvm/projects/libcxxabi
