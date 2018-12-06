template <unsigned long ...>
struct index_sequence;

template <typename T>
struct foo;

template <unsigned long ...i>
struct foo<index_sequence<i...>> {
  static using apply(auto ...x) {
    static_assert(sizeof...(i) == 5);
    static_assert(sizeof...(x) == 3);
    // should fail because the pack sizes are different
    return ((x + i) + ...);
  }
};

int main() {
  int x = foo<index_sequence<0, 1, 2, 3, 4>>::apply(25 , 15, 2);
}
