//
// Created by Jaxon Keeler on 10/19/17.
//

#ifndef MEMMAPPEDQ_ARRAYQ_H
#define MEMMAPPEDQ_ARRAYQ_H

#include "IQueue.h"

class ArrayQ : public IQueue
{
public:
  ArrayQ();
  virtual ~ArrayQ();
  void enqueue(int item) override;
  int dequeue() override;

private:
  int items[1024];
  int capacity = 1024; //make this dynamic
  int head;
  int tail;

  bool isEmpty() override { return tail == -1; }
  void circularIncr(int &index);

};

#endif //MEMMAPPEDQ_ARRAYQ_H
