#include <functional>
#include <semaphore>
using namespace std;

class FizzBuzz {
private: 
    int n;
 counting_semaphore<1> semNumber{1};
    counting_semaphore<1> semFizz{0};
    counting_semaphore<1> semBuzz{0};
    counting_semaphore<1> semFizzBuzz{0};

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        
        for(int i=3;i<=n; i+=3){
            if(i%5==0)continue;
            semFizz.acquire();
            printFizz();
            semNumber.release();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {

          for(int i=5;i<=n; i+=5){
            if(i%3==0)continue;
            semBuzz.acquire();
            printBuzz();
            semNumber.release();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         for(int i=15;i<=n; i+=15){
            semFizzBuzz.acquire();
            printFizzBuzz();
            semNumber.release();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=n; i++){
            semNumber.acquire();
            if(i%3==0 && i%5==0) semFizzBuzz.release();
            else if(i%3==0)semFizz.release();
            else if(i%5==0)semBuzz.release();
            else{
                printNumber(i);
                semNumber.release();
            }
        }
    }
};