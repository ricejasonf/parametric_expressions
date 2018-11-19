#include <cassert>
#include <utility>

template <typename ...T>
int add(T ...x) {
  return (x + ...);
}

template <typename T>
struct foo;

template <unsigned long ...i>
struct foo<std::index_sequence<i...>> {
  using apply(auto ...x) {
    static_assert(sizeof...(i) == 5);
    static_assert(sizeof...(x) == 3);
    // should fail because the pack sizes are different
    return ((x + i) + ...);
  }
};

int main() {
  int x = foo<std::make_index_sequence<5>>::apply(25 , 15, 2);
  assert(x == 45);
}
