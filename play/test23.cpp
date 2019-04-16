// (Taken from http://ldionne.com/P1221-presentation/#/9)
// Test transparent AST node

#include <cassert>
#include <utility>

struct blah { };

using twice(using auto x) { return x * 2; }

template <typename T, typename = decltype(twice(std::declval<T>()))>
auto foo(T x) {
  return twice(x);
}

template <typename T>
auto foo(...) {
  return "not implemented";
}

int main() {
  constexpr auto x = foo(1);
  assert(foo(3) == 6); // OK
  assert(foo(blah{}) == "not implemented"); // OK, would normally be an error
}
