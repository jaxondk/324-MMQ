//
// Created by Jaxon Keeler on 10/19/17.
//

#include "ArrayQ.h"

ArrayQ::ArrayQ() //(int capacity)
{
//  items = new int[capacity]; //careful. Will probs need to delete this in destructor
//  this->capacity = capacity;
  head = -1;
  tail = -1;
}

ArrayQ::~ArrayQ()
{
//  delete items;
}

void ArrayQ::enqueue(int item)
{
  circularIncr(tail);
  items[tail] = item;
  if(head == -1)
    head = 0;
}

int ArrayQ::dequeue()
{
  IQueue::dequeue(); //checks if Q is empty and throws exception if so
  int item = items[head];
  circularIncr(head);
  return item;
}

void ArrayQ::circularIncr(int &index)
{
  if(index != -1 && index + 1 == capacity)
    index = (index + 1) % capacity;
  else
    index++;
}