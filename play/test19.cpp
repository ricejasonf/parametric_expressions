#include <cassert>

using fwd(auto x) {
  return static_cast<decltype(x)>(x);
}

using to_pack~(using auto ...x) {
  return x;
}

using int_seq~(using auto ...i) {
  return i;
}

struct my_array {
  int storage[5];

  using get(auto self, using auto i) {
    return self.storage[i];
  }

  using operator[](auto self, auto i) {
    return self.storage[i];
  }

  using operator()~(using auto self) {
    // this still expands to multiple binds
    // which is bad but perhaps expected when
    // you look at the user code
    return self.storage[int_seq~(0, 1, 2, 3, 4)];
  }
};

using foo(auto ...x) { }

int main() {
  {
    int xs[] = {0, 1, 2};
    int sum = (xs[int_seq~(0, 1, 2)] + ...);
    assert(sum == 3);
  }
  {
    my_array xs = {0, 1, 2};
    int sum = (xs.get(int_seq~(0, 1, 2)) + ...);
    assert(sum == 3);
  }
  {
    my_array xs = {0, 1, 2};
    int sum = (xs[int_seq~(0, 1, 2)] + ...);
    assert(sum == 3);
  }
  {
    my_array xs = {0, 1, 2, 3, 4};
    foo(xs~...);

    int sum = (xs~ + ...);
    assert(sum == 10);

  }
  {
    // this would construct a my_array 5 times
    int sum = (my_array{0, 1, 2, 3, 4}~ + ...);
    assert(sum == 10);
  }
}
