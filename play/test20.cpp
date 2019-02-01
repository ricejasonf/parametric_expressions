// unnamed constexpr params that were of "aggregate"
// were causing a crash when it tried to mangle the name.
struct bar { };

using foo(constexpr auto) { }
int main() {
  foo(bar{});
}
