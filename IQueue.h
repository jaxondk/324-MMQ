//
// Created by Jaxon Keeler on 10/19/17.
//

#ifndef MEMMAPPEDQ_IQUEUE_H
#define MEMMAPPEDQ_IQUEUE_H

#include "EmptyQException.h"

//#define QUEUE_CAPACITY    1024


//Must have only pure virtual functions. Of form: virtual f(x) decl = 0;
class IQueue
{
public:
  virtual void enqueue(int item) = 0;
  virtual int dequeue()
  {
    if(isEmpty()) throw EmptyQException();
  }

private:
  virtual bool isEmpty() = 0;

};

#endif //MEMMAPPEDQ_IQUEUE_H
