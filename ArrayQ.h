//
// Created by Jaxon Keeler on 10/19/17.
//

#ifndef MEMMAPPEDQ_ARRAYQ_H
#define MEMMAPPEDQ_ARRAYQ_H

#include "IQueue.h"

class ArrayQ : public IQueue
{
public:
  ArrayQ();//(int capacity);
  virtual ~ArrayQ();
  virtual void enqueue(int item);
  virtual int dequeue();

private:
  int items[QUEUE_CAPACITY];
  int capacity = QUEUE_CAPACITY;
  int head;
  int tail;

  virtual bool isEmpty() { return tail == -1; }
  virtual void circularIncr(int &index);

};

#endif //MEMMAPPEDQ_ARRAYQ_H
