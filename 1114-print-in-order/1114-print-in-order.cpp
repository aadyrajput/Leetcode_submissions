class Foo {
public:
     int ct=0;
        mutex mtx;
        condition_variable cv;
    Foo() {
        ct=1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ct=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
         while(ct!=2) cv.wait(lck);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ct=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while(ct!=3) cv.wait(lck);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};