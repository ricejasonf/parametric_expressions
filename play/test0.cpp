#include <iostream>
#include <type_traits>

constexpr auto print_type_e = [](auto&& x) {
  using X = decltype(x);
  std::cout << typeid(x).name() 
            << ' '
            << (std::is_const_v<std::remove_reference_t<X>> ? "const" : "     ")
            << (std::is_lvalue_reference_v<X> ? "& " : "")
            << (std::is_rvalue_reference_v<X> ? "&&" : "")
            << "; ";
};

using print_type(auto x) {
  using X = decltype(x);
  std::cout << typeid(x).name() 
            << ' '
            << (std::is_const_v<std::remove_reference_t<X>> ? "const" : "     ")
            << (std::is_lvalue_reference_v<X> ? "& " : "")
            << (std::is_rvalue_reference_v<X> ? "&&" : "")
            << '\n';
}

int main()
{
  int x = 42;
  int& y = x;
  int const& z = x;
  int const a = x;
  print_type_e(x); print_type(x);
  print_type_e(y); print_type(y);
  print_type_e(z); print_type(z);
  print_type_e(a); print_type(a);
  print_type_e(42); print_type(42);
}
