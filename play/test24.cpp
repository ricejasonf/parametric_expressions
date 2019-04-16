#include <utility>

using funcify(using auto f) {
  return [](auto&& ...x)
    noexcept(noexcept(f(std::forward<decltype(x)>(x))))
    -> decltype(f(std::forward<decltype(x)>(x)...))
    { return f(std::forward<decltype(x)>(x)...); };
}

struct make_array_impl {
  using operator()(using auto ...x) {
    return std::array<std::common_type<decltype(x)...>, sizeof...(x)>{x...};
  }
};

constexpr auto make_array = funcify(make_array_impl{});

int main() {
  make_array(5);
}
