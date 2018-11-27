#include <cassert>

struct foo {
  int value;

  using or_(using auto x) {
    if (value) return *this;
    else return foo{x};
  }
};

int main()
{
  foo result = foo{5}.or_(6);
  assert(result.value == 5);
}
