#include <cassert>

namespace blah {
  struct foo {
    int value;

    // member candidate
    using operator||(auto self, using auto x) {
      if (self.value) return self;
      else return foo{x};
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
  else return self;
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
}
