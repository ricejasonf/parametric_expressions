#include <cassert>

struct foo {
  int value;

  using add(using auto self, using auto x) {
    return foo{x.value + self.value};
  }
};

int main()
{
  foo result = foo{5}.add(foo{37});
  assert(result.value == 42);
}
