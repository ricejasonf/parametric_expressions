#include <iostream>

using if_(auto cond, using auto a, using auto b) {
  int x = 5;
  if (cond) return a;
  else      return b + 5;
}

using print(auto t) {
  std::cout << t << '\n';
  return t;
}

int main() {
  int x = 42;
  int y = if_(x >= 42, print(x), print(5));
  void(print(y));
}
