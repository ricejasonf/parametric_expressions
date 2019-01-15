#include <iostream>
#include <type_traits>

#define RL std::cout << '\n';

#define PRINT_TYPE(x) { \
  using X = decltype(x); \
  std::cout << typeid(x).name() \
            << ' ' \
            << (std::is_const_v<std::remove_reference_t<X>> ? "const" : "     ") \
            << (std::is_lvalue_reference_v<X> ? "& " : "") \
            << (std::is_rvalue_reference_v<X> ? "&&" : "") \
            << "; "; }

constexpr auto print_type_e = [](auto&& x) {
  PRINT_TYPE(x);
};

using print_type(auto x) {
  PRINT_TYPE(x);
}

constexpr auto id_e = [](auto&& x)
  -> decltype(auto)
{
  return static_cast<decltype(x)>(x);
};

using id(auto x) {
  return static_cast<decltype(x)>(x);
};

int main()
{
  int x = 42;
  int& y = x;
  int const& z = x;
  int const a = x;
  print_type_e(x); print_type(x); RL
  print_type_e(y); print_type(y); RL
  print_type_e(z); print_type(z); RL
  print_type_e(a); print_type(a); RL
  print_type_e(42); print_type(42); RL

  std::cout << '\n';

  PRINT_TYPE(id_e(x));  PRINT_TYPE(id(x)); RL
  PRINT_TYPE(id_e(y));  PRINT_TYPE(id(y)); RL
  PRINT_TYPE(id_e(z));  PRINT_TYPE(id(z)); RL
  PRINT_TYPE(id_e(a));  PRINT_TYPE(id(a)); RL
  PRINT_TYPE(id_e(42)); PRINT_TYPE(id(42)); RL
}
