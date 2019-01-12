#include <cassert>

using compose(using auto f, using auto g) {
  return [=](auto x){ return f(g(x)); };
}

using compose2(using auto f, using auto g) {
  struct local {
    static using operator()(auto x)
    { return f(g(x)); };
  };
  return local{};
}

#if 0 // sorry, but these end up in late parsing
         weirdness that is not currently supported
using compose3(using auto f, using auto g) {
  struct local {
    int operator()(int x)
    { return f(g(x)); };
  };
  return local{};
}

using compose4(using auto f, using auto g) {
  struct local {
    template <typename T>
    auto operator()(T x)
    { return f(g(x)); };
  };
  return local{};
}
#endif

int dbl(int i) { return i*2; }
int next(int i) { return ++i; }
auto z = compose(dbl, next);
auto z2 = compose2(dbl, next);
#if 0
auto z3 = compose3(dbl, next);
auto z4 = compose4(dbl, next);
#endif

int main() {
  assert(z(5) == 12);
  assert(z2(5) == 12);
#if 0
  assert(z3(5) == 12);
  assert(z4(5) == 12);
#endif
}
