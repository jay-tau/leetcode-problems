class Foo {
 private:
  vector<bool> state;

 public:
  Foo() { state.resize(2, false); }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    state[0] = true;
  }

  void second(function<void()> printSecond) {
    while (!state[0]);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    state[1] = true;
  }

  void third(function<void()> printThird) {
    while (!state[1]);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};