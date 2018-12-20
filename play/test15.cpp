using drop_front(using auto, using auto ...pack) {
  return pack;
}

using sum(using auto ...xs) {
  return xs;
}

int main() {
  int x = sum(drop_front(1, 2, 3, 4)...);
}
