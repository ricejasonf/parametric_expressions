cmake_minimum_required(VERSION 3.10)
project(project_sema_bench)

set(LLVM_PATH ../build_release)
link_directories(${LLVM_PATH}/lib)
include_directories(${LLVM_PATH}/include)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-fno-rtti)

function(semabench_link_clang target_name)
  target_link_libraries(${target_name}
    clangFrontend
    clangSerialization
    clangDriver
    clangParse
    clangSema
    clangAnalysis
    clangAST
    clangBasic
    clangEdit
    clangLex
    clangTooling

    # llvm libs
    LLVMX86AsmParser
    LLVMX86Desc
    LLVMX86AsmPrinter
    LLVMX86Info
    LLVMX86Utils
    LLVMipo
    LLVMScalarOpts
    LLVMInstCombine
    LLVMTransformUtils
    LLVMipa
    LLVMAnalysis
    LLVMTarget
    LLVMOption
    LLVMMCParser
    LLVMMC
    LLVMObject
    LLVMBitReader
    LLVMCore
    LLVMSupport
  )
endfunction()

add_executable(bench1 ${SOURCE_FILES})

semabench_link_clang(bench1)
