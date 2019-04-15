#include <cassert>
#include <cstdlib>
#include <iostream>

using if_(auto cond, using auto a, using auto b) {
  int x = 5;
  if (cond) return a + x;
  else      return b + x;
}

using print(auto t) {
  std::cout << t << '\n';
  return t;
}

int main() {
  int x = 42;
  int y = if_(x >= 42, print(x), print(5));
  void(print(y));
  assert(y == 47);
}
