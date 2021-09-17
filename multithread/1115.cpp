#include <semaphore.h>

class FooBar
{
public:
    FooBar(int x);
    void foo(function<void()> printfoo);
    void bar(function<void()> printbar);

private:
    int n;
    sem_t foo_done;
    sem_t bar_done;
};

FooBar::FooBar(int x)
{
    n = x;
    sem_init(&foo_done, 0, 0);
    sem_init(&bar_done, 0, 1);
}

void FooBar::foo(function<void()> printfoo)
{
    for (int i = 0; i < n; i++)
    {
        sem_wait(&bar_done);
        printfoo();
        sem_post(&foo_done);
    } 

}

void FooBar::bar(function<void()> printbar)
{
    for (int i = 0; i < n; i++)
    {
        sem_wait(&foo_done);
        printbar();
        sem_post(&bar_done);
    }
    
}
