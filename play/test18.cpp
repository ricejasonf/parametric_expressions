#include <cassert>
#include <utility>

using fwd(using auto x) {
  return static_cast<decltype(x)>(x);
}

template <typename T, int N>
struct foo {
  char storage[N];

  using operator[](using auto self, auto n) {
    return fwd(self).storage[n];
  }

  // FIXME we should make arrow ops
  // implicitly convert the pointer to a 
  // reference... somehow
  using get(auto self, auto n) {
    return self->storage[n];
  }
};

template <typename T>
struct smart_ptr {
  T* value;

  using operator->(auto self) {
    return self.value;
  }
};

int main() {
  foo<int, 5> x{{0, 1, 2, 3, 4}};
  assert(x[0] == 0);
  assert(x[1] == 1);
  assert(x[2] == 2);
  assert(x[3] == 3);
  assert(x[4] == 4);

  smart_ptr<foo<int, 5>> s{new foo<int, 5>{x}};
  assert(s->get(0) == 0);
  assert(s->get(1) == 1);
  assert(s->get(2) == 2);
  assert(s->get(3) == 3);
  assert(s->get(4) == 4);
}
