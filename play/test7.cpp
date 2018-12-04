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
  using apply(using auto f, auto ...x) {
    return f(x...);
  }
};

using baz(using auto x) {
  return x;
}

using bar(auto y) {
  return baz(y);
}

int main() {
  int x = foo<int>::apply(add, 25, 15, 2);
                       // ^ Overloaded Function!!
  assert(x == 42);

  int y = foo<int>::apply(addp, 25, 15, 2);
                       // ^ Parametric Expression Id!!
  assert(y == 42);

  assert(bar(5) == 5);
}
