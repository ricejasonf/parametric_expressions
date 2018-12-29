FROM ubuntu:bionic as parmexpr_build

  RUN apt-get update && apt-get -y install git cmake build-essential

  RUN git clone --depth 1 \
                -b e90d44039a60317e8379232d5c43dc06cef8f463 \
                https://github.com/llvm-mirror/llvm.git \
   && cd emscripten-fastcomp/tools/ \
   && git clone --depth 1 \
                -b parmexpr \
                https://github.com/ricejasonf/clang.git clang \
   && cd ../projects \
   && git clone --depth 1 \
                -b 61b0a0088b54793b2d4e7fc2f1b1a1f3893293a8 \
                 https://github.com/llvm-mirror/libcxx.git \
   && git clone --depth 1 \
                -b bd80f6625dec55d43bab409ab0b71b94472eff28 \
                 https://github.com/llvm-mirror/libcxxabi.git \
   && cd ../ && mkdir build && cd build \
   && cmake \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DLLVM_TARGETS_TO_BUILD="X86;" \
      -DLLVM_INCLUDE_EXAMPLES=OFF -DLLVM_INCLUDE_TESTS=OFF \
      -DCLANG_INCLUDE_EXAMPLES=OFF -DCLANG_INCLUDE_TESTS=OFF \
      .. \
   && make -j4 && make install

FROM ubuntu:bionic

  COPY --from=parmexpr_build /usr/local/lib /usr/local/lib
  COPY --from=parmexpr_build /usr/local/include /usr/local/include
  COPY --from=parmexpr_build /usr/local/bin /usr/local/bin
