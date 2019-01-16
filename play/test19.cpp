using int_seq(using auto ...i) {
  return i;
}

struct my_array {
  int storage[5];

  decltype(auto) operator[](int i) {
    return storage[i];
  }

  decltype(auto) get(int i) {
    return storage[i];
  }
};

int main() {
  {
    int xs[] = {0, 1, 2};
    int sum = (xs[int_seq(0, 1, 2)] + ...);
  }
  {
    my_array xs = {0, 1, 2};
    int sum = (xs.get(int_seq(0, 1, 2)) + ...);
  }
  {
    my_array xs = {0, 1, 2};
    int sum = (xs[int_seq(0, 1, 2)] + ...);
  }
}
