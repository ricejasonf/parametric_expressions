#include <cassert>

template <typename ...T>
int add(T ...x) {
  return (x + ...);
}

using addp(using auto ...x) {
  return (x + ...);
}

template <typename T>
struct foo {
  int value;

  using apply(using auto f, auto ...x) {
    return f(value, x...);
  }
};

// bar/baz are a simplified test of a bugfix
using baz(using auto x) {
  return x;
}

using bar(auto y) {
  return baz(y);
}

int main() {
  int x = foo<int>{1}.apply(add, 25, 15, 1);
                         // ^ Overloaded Function!!
  assert(x == 42);

  int y = foo<int>{1}.apply(addp, 25, 15, 1);
                         // ^ Parametric Expression Id!!
  assert(y == 42);

  assert(bar(5) == 5);
}
