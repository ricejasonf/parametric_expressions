#include <cassert>
#include <utility>

using id(using auto x) {
  return x;
}

using invoke(using auto fn, auto x) {
  return fn(static_cast<decltype(x)>(x));
}

// this is bad but it should work
using pair_twice(using auto fn) {
  return std::pair{fn, fn};
}

using lam(using auto fn) {
  return [&](auto ...args) {
    return fn(args...);
  };
}

using double_lam(using auto fn) {
  return [](auto ...args) {
    return [](auto ...args) {
      return fn(args...);
    }(args...);
  };
}

int main() {
  auto fn = id([](auto x) { return x; });
  assert(fn(5) == 5);

  assert(invoke([](auto x) { return x; }, 42) == 42);

  auto pair = pair_twice([](auto x) { return x; });
  static_assert(not std::is_same_v<decltype(pair.first), decltype(pair.second)>);

  assert(lam([](auto x) { return x; })(102) == 102);
  assert(lam([](auto x) { return x; })('c') == 'c');

  assert(double_lam([](auto x) { return x; })(1234) == 1234);
}
