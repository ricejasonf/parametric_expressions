CXX_COMPILER=../build/bin/clang++
LIST = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
targets = $(addprefix test, $(LIST))
define make-test-target
  test$1: test$1.cpp
		${CXX_COMPILER} -g -O0 -std=c++2a -stdlib=libc++ test$1.cpp -o ./build/test$1

  asm_test$1: test$1.cpp
		${CXX_COMPILER} -g -O0 -S -emit-llvm -std=c++2a -stdlib=libc++ test$1.cpp -o ./build/test$1.ll

  ast_test$1: test$1.cpp
		${CXX_COMPILER} -g -O0 -ast-dump -std=c++2a -stdlib=libc++ test$1.cpp -o ./build/test$1.s

  gdb_test$1: test$1.cpp
		gdb \
			-ex "set follow-fork-mode child" \
			--args ${CXX_COMPILER} -g -O0 -S -std=c++2a -stdlib=libc++ test$1.cpp -o ./build/test$1.s

  run_test$1: test$1
		./build/test$1
endef

$(foreach element,$(LIST),$(eval $(call make-test-target,$(element))))
