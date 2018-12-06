//#include <cassert>

struct foo {
  int value;

  using operator||(using auto x) {
    if (value) return *this;
    else return foo{x};
  }
};

int main() {
  foo result = foo{5} || foo{6};
  //assert(result.value == 5);
}
