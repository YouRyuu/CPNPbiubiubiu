#include <semaphore.h>
class Foo {
public:
    sem_t sem1, sem2;
    Foo() {
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&sem1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&sem2);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
