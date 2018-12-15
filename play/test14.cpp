using foo(constexpr auto x) {
  static_assert(x);
}

int main() {
  constexpr int x = 5;
  foo(x);
}
