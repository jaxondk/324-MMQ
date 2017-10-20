//
// Created by Jaxon Keeler on 10/19/17.
//

#ifndef MEMMAPPEDQ_EMPTYQEXCEPTION_H
#define MEMMAPPEDQ_EMPTYQEXCEPTION_H

#include <exception>

class EmptyQException : public std::exception
{
  virtual const char* what() const throw()
  {
    return "Cannot dequeue: the queue is empty";
  }
};

#endif //MEMMAPPEDQ_EMPTYQEXCEPTION_H
