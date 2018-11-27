#include <cassert>

struct foo {
  int value;

  using add(using auto x) {
    return foo{x.value + value};
  }
};

int main()
{
  foo result = foo{5}.add(foo{37});
  assert(result.value == 42);
}
