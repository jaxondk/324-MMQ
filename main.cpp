#include <iostream>
#include <sys/time.h>
#include <assert.h>
#include "IQueue.h"
#include "ArrayQ.h"

const int TEST_SIZE = 3000;
const int QUEUE_CAPACITY = 30;
const int NUM_ITEMS_INSERT = 30;

double When()
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);
}

void test(IQueue* queue)
{
  for (int i = 0; i < NUM_ITEMS_INSERT; ++i) //what is supposed to happen if you insert more items than the Q has capacity for? do the first items in the Q get overwritten with the last ones?
  {
    queue->enqueue(i);
  }
  assert(queue->dequeue() == 0);
  queue->enqueue(99);
  for (int i = 1; i < NUM_ITEMS_INSERT; ++i)
  {
    assert(queue->dequeue() == i);
  }
  assert(queue->dequeue() == 99);
}

double getAvgTime(IQueue* queue)
{
  double start = When();
  for (int i = 0; i < TEST_SIZE; ++i)
  {
    test(queue);
  }
  double stop = When();

  return stop - start;
}

int main()
{
  ArrayQ arrayQ; //(QUEUE_CAPACITY);
//  LLQ llq(QUEUE_CAPACITY);
//  MMQ mmq(QUEUE_CAPACITY);

  test(&arrayQ);
//  std::cout << "Average time for array implementation: " << getAvgTime(&arrayQ) << std::endl;
//  std::cout << "Average time for linked list implementation: " << getAvgTime(&llq) << std::endl;
//  std::cout << "Average time for memory-mapped implementation: " << getAvgTime(&mmq) << std::endl;

  return 0;
}

