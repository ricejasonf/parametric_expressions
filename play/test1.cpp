#include <cassert>

struct doop {
  int value;
};

using foo(using auto expr1, using auto expr2)
{
  return expr1 + expr2;
}

using id(using auto x) {
  return x;
}

using inc(using auto x)
{
  return id(x + 1);
}

using id_(auto x) {
  return static_cast<decltype(x)>(x);
}

int main()
{
  int x = foo(40, 2);
  int y = inc(foo(40, 3));

  assert(x == 42);
  assert(y == 44);

  doop d{5};
  doop& r = id_(d);
}
