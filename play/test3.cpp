#include <cassert>

using lazy(using auto x) {
  return [&] { return x; };
}

int main() {
  int x = 5;
  auto f = lazy(x += 3);

  assert(x == 5);
  f();
  assert(x == 8);
}
