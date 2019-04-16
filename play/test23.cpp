// (Taken from http://ldionne.com/P1221-presentation/#/9)
// Test transparent AST node

#include <cassert>
#include <type_traits>

using twice(using auto x) { return x * 2; }

template <typename T, typename = decltype(twice(std::declval<T>()))>
auto foo(T x) {
  return twice(x);
}

auto foo(...) {
  return "not implemented";
}

struct blah { };

int main() {
  constexpr auto x = twice(1);
  assert(foo(3) == 6); // OK
  assert(foo(blah{}) == "not implemented"); // OK, would normally be an error
}
