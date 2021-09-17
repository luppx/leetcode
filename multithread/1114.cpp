#include <semaphore.h>
using namespace std;

class Foo
{
private:
    sem_t firstJobDone;
    sem_t secondJobDone;

public:
    Foo();
    ~Foo();
    void first(function<void()> printFirst);
    void second(function<void()> printSecond);
    void third(function<void()> printThird);
};

Foo::Foo()
{
    sem_init(&firstJobDone, 0, 0);
    sem_init(&secondJobDone, 0, 0);
}

Foo::~Foo()
{
}

void Foo::first(function<void()> printFirst)
{
    printFirst();
    sem_post(&firstJobDone);
}

void Foo::second(function<void()> printSecond)
{
    sem_wait(&firstJobDone);
    printSecond();
    sem_post(&secondJobDone);
}

void Foo::third(function<void()> printThird)
{
    sem_wait(&secondJobDone);
    printThird();
}

