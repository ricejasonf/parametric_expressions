template <typename T>
struct foo {
  static using apply(auto x, auto y) {
    return x + y;
  }

  auto bar() { return apply(5, 6); }
};

int main()
{
  int x = foo<int>{}.bar();
  int y = foo<int>::apply(40, 2);
}
