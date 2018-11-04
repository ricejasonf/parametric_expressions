template <typename ...T>
int add(T ...x) {
  return (x + ...);
}

template <typename T>
struct foo {
  using apply(using auto f, auto ...x) {
    return (x + ...);
    //return f(x...);
  }
};

int main() {
  int x = foo<int>::apply(add, 25 , 15, 2);
}
