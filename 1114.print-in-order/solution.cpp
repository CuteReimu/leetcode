#include <unistd.h>

class Foo {
private:
    int i = 0;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i = 1;
    }

    void second(function<void()> printSecond) {
        while (i != 1) {sleep(0);}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i = 2;
    }

    void third(function<void()> printThird) {
        while (i != 2) {sleep(0);}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
