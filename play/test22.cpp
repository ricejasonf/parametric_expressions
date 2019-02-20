template <typename T>
struct foo {
    T t;
};

template <typename T>
struct bar {
static using apply(auto fn) {
    return foo<decltype(fn)>{static_cast<decltype(fn)>(fn)};
}
};

int main() {
  auto x = bar<int>::apply([&](auto x) { });
}
