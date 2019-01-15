#include <cassert>

template <typename T>
auto decay(T&& t) { return t; }

template <bool = true>
struct constexpr_if_detail {
  static using apply(using auto a, using auto) {
    return a;
  }
};

template <>
struct constexpr_if_detail<false> {
  static using apply(using auto, using auto b) {
    return b;
  }
};

struct constexpr_if_fn {
  using operator()(using auto self, constexpr auto cond,
                   using auto a, using auto b) {
    return constexpr_if_detail<cond>::apply(a, b);
  }
} inline constexpr_if{};

namespace blah {
  struct foo {
    int value;

    // member candidate
    using operator||(auto self, using auto x) {
      if (self.value) return decay(self);
      else return foo{x};
    }

    using operator++(auto self, using auto ...tag) {
      return constexpr_if(sizeof...(tag) == 0,
                          (self.value++, self),
                          foo{self.value++});
    }
  };

  // non-member candidate found via ADL
  using operator==(using auto self, using auto x) {
    return self.value == x.value;
  }
}

// non-member candidate
using operator&&(auto self, using auto x) {
  if (self.value) return blah::foo{x};
  else return decay(self);
}

int main() {
  using foo = blah::foo;

  //member

  {
    foo result1 = foo{5} || foo{6};
    assert(result1.value == 5);

    foo result2 = foo{0} || foo{6};
    assert(result2 == foo{6});

    foo result3 = foo{5}.operator||(6);
    assert(result3 == foo{5});
  }

  // non-member

  {
    foo result1 = foo{5} && foo{6};
    assert(result1 == foo{6});

    foo result2 = foo{0} && foo{6};
    assert(result2 == foo{0});
  }

  // unary

  {
    foo result1 = foo{5}++;
    assert(result1 == foo{5});

    foo result2 = ++foo{5};
    assert(result2 == foo{6});
  }
}
