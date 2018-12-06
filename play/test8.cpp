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
  static using apply(auto ...x) {
    static_assert(sizeof...(x) == 3);
    return ((x + i) + ...);
  }
};

int main() {
  int x = foo<std::make_index_sequence<3>>::apply(25 , 15, 2);
  assert(x == 45);
}
