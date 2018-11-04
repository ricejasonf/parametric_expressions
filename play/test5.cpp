#include <iostream>

struct foo {
  using apply(auto x, auto y) {
    return x + y;
  }
};

int main()
{
  int x = foo::apply(40, 2);
  std::cout << x << '\n';
  void(foo::apply(40, 2));
}
