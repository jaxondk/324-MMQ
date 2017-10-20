//
// Created by Jaxon Keeler on 10/20/17.
//

#ifndef MEMMAPPEDQ_MMQ_H
#define MEMMAPPEDQ_MMQ_H

#include "IQueue.h"

class MMQ : public IQueue
{
public:
  MMQ(int capacity);

  void enqueue(int item) override;
  int dequeue() override;

private:
  virtual bool isEmpty() override { return tail == nullptr; }
  int* head;
  int* tail;
  int fd;
  int* buffer;
  int capacity;
  size_t pagesize;
};

#endif //MEMMAPPEDQ_MMQ_H
