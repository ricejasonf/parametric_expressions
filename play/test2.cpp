#include <cassert>

struct my_int {
  int value;

  my_int operator+(my_int b) {
    return my_int{value + b.value};
  }
};

using foo(auto expr1, auto expr2)
{
  return expr1 + expr2;
}

int main()
{
  int x = foo(40, 2);
  my_int my_x = my_int{x};
  my_int my_y = foo(my_x, my_int{3});

  assert(x          == 42);
  assert(my_y.value == 45);
}
