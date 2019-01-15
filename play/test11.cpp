#include <cassert>

template <typename T>
auto decay(T&& t) {
  return t;
}

struct foo {
  int value;

  // I think implementing NRVO would
  // fix this little problem
  // foo(foo const&) = delete;

  using or_(auto self, using auto x) {
    if (self.value) return decay(self);
    else return foo{x};
  }
};

int main()
{
  foo result = foo{5}.or_(foo{6});
  assert(result.value == 5);
}
