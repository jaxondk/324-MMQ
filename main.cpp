#include <iostream>
#include <sys/time.h>
#include <cassert>
#include <unistd.h>
#include "IQueue.h"
#include "ArrayQ.h"
#include "LLQ.h"
#include "MMQ.h"

const int TEST_SIZE = 3000;
const int QUEUE_CAPACITY = getpagesize() / sizeof(int);
const int NUM_ITEMS_INSERT = QUEUE_CAPACITY;

double When()
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);
}

int test(IQueue* queue)
{
  int ops = 0;
  for (int i = 0; i < NUM_ITEMS_INSERT; ++i)
  {
    queue->enqueue(i);
    ops++;
  }
  assert(queue->dequeue() == 0);
  queue->enqueue(99);
  ops += 2;
  for (int i = 1; i < NUM_ITEMS_INSERT; ++i)
  {
    assert(queue->dequeue() == i);
    ops++;
  }
  assert(queue->dequeue() == 99);
  ops++;
  return ops;
}

double getAvgTime(IQueue* queue)
{
  int ops = 0;
  double start = When();
  for (int i = 0; i < TEST_SIZE; ++i)
  {
    ops += test(queue);
  }
  double stop = When();

  return (stop - start) / ops;
}

int main()
{
  ArrayQ arrayQ;
  LLQ llQ;
  MMQ mmQ(QUEUE_CAPACITY);

  std::cout << "Number of ops for one test: " << test(&mmQ) << ". # of tests per implementation: " << TEST_SIZE << std::endl;
  std::cout << "Average time for array implementation: " << getAvgTime(&arrayQ) << std::endl;
  std::cout << "Average time for linked list implementation: " << getAvgTime(&llQ) << std::endl;
  std::cout << "Average time for memory-mapped implementation: " << getAvgTime(&mmQ) << std::endl;

  return 0;
}

