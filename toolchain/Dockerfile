FROM ricejasonf/cppdock as parmexpr_build
  WORKDIR /opt/src
  RUN cppdock install_src e90d44039a60317e8379232d5c43dc06cef8f463 \
                          llvm-mirror/llvm      ./llvm
  RUN cppdock install_src 7a4b1568bb1f31e61b014512a8fcf54af06cf173 \
                          ricejasonf/clang      ./llvm/tools/clang
  RUN cppdock install_src 61b0a0088b54793b2d4e7fc2f1b1a1f3893293a8 \
                          llvm-mirror/libcxx    ./llvm/projects/libcxx
  RUN cppdock install_src bd80f6625dec55d43bab409ab0b71b94472eff28 \
                          llvm-mirror/libcxxabi ./llvm/projects/libcxxabi

  RUN  apt-get update && apt-get -yq install build-essential

  WORKDIR /opt/build/
  RUN cmake \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DLLVM_TARGETS_TO_BUILD="X86;" \
      -DLLVM_INCLUDE_EXAMPLES=OFF -DLLVM_INCLUDE_TESTS=OFF \
      -DCLANG_INCLUDE_EXAMPLES=OFF -DCLANG_INCLUDE_TESTS=OFF \
      /opt/src/llvm \
   && make -j4 && make install

  # Include Metabench for convenience
  WORKDIR /opt/src
  RUN cppdock install_src ad7b519b3ab8b67e5ce3ceccf0d4cd8d77c52cf4 \
                          ldionne/metabench ./metabench

FROM ricejasonf/cppdock
  RUN  apt-get update && apt-get -yq install libc++1

  COPY --from=parmexpr_build /usr/local/lib /usr/local/lib
  COPY --from=parmexpr_build /usr/local/include /usr/local/include
  COPY --from=parmexpr_build /usr/local/bin /usr/local/bin
  COPY --from=parmexpr_build /opt/src/metabench/metabench.cmake \
    /opt/metabench.cmake
  COPY toolchain.cmake /opt/toolchain.cmake
