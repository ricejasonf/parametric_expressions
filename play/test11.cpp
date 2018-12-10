#include <cassert>

struct foo {
  int value;

  using or_(auto self, using auto x) {
    if (self.value) return self;
    else return foo{x};
  }
};

int main()
{
  foo result = foo{5}.or_(6);
  assert(result.value == 5);
}
