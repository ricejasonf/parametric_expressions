template <typename T>
struct foo {
  int value = 5;

  static using apply(auto x, auto y) {
    return x + y;
  }

  auto bar() { return apply(5, 6); }

  using baz(auto self)
  { return apply((self.value), 42 - self.value); }
};

int main() {
  int x = foo<int>{}.bar();
  int y = foo<int>::apply(40, 2);

  foo<long> foo_const = {};
  int z = foo_const.baz();
  int zz = foo_const.apply(40, 2);
  int zzz = foo<int>{}.baz();
}
