// FILE: queue.h
// CLASS PROVIDED queue
//
// DEFAULT VALUES
//  DEFAULT_SIZE
//      Default size of the queue if none is provided by the user
//
// CONSTRUCTORS
//  queue(size_t array_size = DEFAULT_SIZE)
//      Initializes an empty queue with array_size elements
//
// MUTATORS:
//  void push(T in)
//      Enqueues an element into the queue
//
//  void pop()
//      Dequeues, or removes, an element from the queue
//
// ACCESSORS:
//  T queue_front()
//      Returns the element at the front of the queue
//
//  bool empty()
//      Returns true if the queue is empty, otherwise false
//
//  int size()
//      Returns the number of elements in the queue

#ifndef QUEUE
#define QUEUE

#include <iostream>

template<typename T>
class queue {
    public:
        // DEFAULT VALUES
        static const size_t DEFAULT_SIZE = 10;

        // CONSTRUCTOR && DECONSTRUCTOR
        queue(size_t array_size = DEFAULT_SIZE) : arr(new T[arr_size]), arr_size(array_size), front(-1), rear(-1) { }

        // mutators
        void push(T in) {
            rear = (rear+1 == arr_size) ? 0 : rear + 1;

            if (front == -1) { front = 0; }

            arr[rear] = in;
        }
        void pop() {
            if (front == -1) {
                return;
            }

            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front+1 == arr_size) ? 0 : front + 1;
            }
        }

        // accessors
        T queue_front() {
            return arr[front];
        }
        bool empty() {
            return (front == -1) ? true : false;
        }
        int size() {
            return rear-front + 1;
        }
    private:
        // size of array
        size_t arr_size;

        T* arr;

        // front of queue
        size_t front;

        // end of queue
        size_t rear;
};

#endif