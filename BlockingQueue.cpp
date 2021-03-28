/* Blocking Queue implemention in C++ using mutex, unique_lock and condition variable*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;
#define MAX_CAPACITY 5

class BlockingQueue
{
private:
        mutex mtx;
        condition_variable not_full, not_empty;
        queue < int >elements;
        int _capacity;

public:  
        BlockingQueue ():_capacity (MAX_CAPACITY)
         {
         }
         
         BlockingQueue (int capacity):_capacity (capacity)
         {
         }
 
         bool isFull ();
         bool isEmpty ();
         void push (int data);
         void pop ();
};


bool BlockingQueue::isFull ()
{
  return (elements.size () == _capacity);
}

bool BlockingQueue::isEmpty ()
{
  return (elements.size () == 0);
}

void BlockingQueue::push (int data)
{
  unique_lock < mutex > lck (mtx);

  if (isFull ())
    not_full.wait (lck);

  elements.push (data);
  cout << "Pushed data to queue" << data << endl;
  not_empty.notify_one ();
}

void BlockingQueue::pop ()
{
  unique_lock < mutex > lck (mtx);

  if (isEmpty ())
    not_empty.wait (lck);

  int temp = elements.front ();
  cout << "Popped data from queue" << temp << endl;
  elements.pop ();

  not_full.notify_one ();
}

void Produce (BlockingQueue& Queue)
{
  for (int i = 0; i < 15; i++)
    {
      Queue.push (i);
     // std::this_thread::sleep_for (std::chrono::milliseconds (60));
    }
}

void Consume (BlockingQueue& Queue)
{
  for (int i = 0; i < 15; i++)
    {
      Queue.pop ();
      std::this_thread::sleep_for (std::chrono::milliseconds (200));
    }
}


int main ()
{
  cout << "Hello Main" << endl;
  BlockingQueue queue(10);
  thread Producer = thread(Produce, ref(queue));
  thread Consumer = thread(Consume, ref(queue));

  Producer.join ();
  Consumer.join ();

  return 0;
}
