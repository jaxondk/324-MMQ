//
// Created by Jaxon Keeler on 10/20/17.
//

#include <sys/mman.h>
#include <fcntl.h>
#include <iostream>
#include <zconf.h>
#include "MMQ.h"

MMQ::MMQ(int capacity)
{
  this->capacity = capacity;
  this->pagesize = capacity * sizeof(int);
  //Use the shm_open function to create a shared memory segment. It returns a file descriptor
  this->fd = shm_open("mysharedsegment", O_RDWR|O_CREAT, 0600);
  //Now force the shared memory segment to the size we need, make sure it is a multiple of pagesize
  ftruncate(this->fd, pagesize*2);

  this->buffer = (int *)mmap(nullptr, pagesize*2, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  mmap(this->buffer, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, this->fd, 0);
  mmap(this->buffer + capacity, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, this->fd, 0); //or can replace 0 with pagesize

  head = buffer;
  tail = nullptr;
}

void MMQ::enqueue(int item)
{
  if(isEmpty())
    tail = head;// = buffer;
  (*tail) = item;
  tail++;
}

int MMQ::dequeue()
{
  IQueue::dequeue();
  int item = (*head);
  head++;
  if(head >= buffer+capacity) //if head gets into the second addr space, move them back into the equiv spot in the first addr space
                            //this is capacity b/c we are using pointer arithmetic
  {
    head -= capacity;
    tail -= capacity;
  }

  return item;
}

