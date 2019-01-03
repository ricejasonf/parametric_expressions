#include <cassert>

// Test instantitations outside of function

template <typename T, typename U>
struct foo;

template <typename T>
struct foo<T, int> {
  int value = 5;

  using get(auto self) {
    return self.value;
  }
};

template <typename T>
struct bar : foo<T, T> {
  foo<T, T> a;
};

struct baz {
  bar<int> a; // should not crash here
};

// should not crash here either
static auto x = baz().a.get();

int main() {
  assert(baz().a.get() == 5);
  assert(x == 5);
}
