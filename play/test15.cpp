#include <cassert>

template <int ...>
struct int_seq { };

template <typename ...>
struct type_seq { };

using drop_front(using auto, using auto ...pack) {
  return pack;
}

using sum(using auto ...xs) {
  return (xs + ...);
}

int main() {
  // call expression
  int x = sum(drop_front(1, 2, 3, 4)...);
  assert(x == 9);

  // braced initializer expression
  int xs[] = {drop_front(1, 2, 3, 4)...};
  assert(xs[0] == 2);
  assert(xs[1] == 3);
  assert(xs[2] == 4);

  // fold expression
  assert((drop_front(void(1), void(2), void(3), 4), ...) == 4);
  assert((drop_front(1, 2, 3, 4) + ...) == 9);
  assert((... + drop_front(1, 2, 3, 4)) == 9);

  // non-type template argument list
  int_seq<2, 3, 4> ints = int_seq<drop_front(1, 2, 3, 4)...>{};

  // type template argument list
  type_seq<int_seq<2>,
           int_seq<3>,
           int_seq<4>> types
    = type_seq<int_seq<drop_front(1, 2, 3, 4)>...>{};

  // type template argument list
  type_seq<int,
           int,
           int       > types_2
    = type_seq<decltype(drop_front(1, 2, 3, 4))...>{};
}
