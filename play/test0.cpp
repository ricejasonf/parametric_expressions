template <typename T>
using Foo = int;

constexpr auto foo = [](auto x) { x + 5; };

int main()
{
  return 42;
}
