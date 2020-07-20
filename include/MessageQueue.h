#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <iostream>
#include <mutex>
#include <deque>
#include <condition_variable>

/*
Template functions, including member functions, must be written entirely in the header file!
*/

template <class T>  
class MessageQueue {
  public:
    T receive(){
      std::unique_lock<std::mutex> lck(mtx);
      _cond.wait(lck, [this](){return !_queue.empty();});
      T msg = std::move(_queue.back());
      _queue.pop_back();
    return msg;
    };

    void send(T &&message){
      std::lock_guard<std::mutex> lck(mtx);
      this->_queue.emplace_back(std::move(message));
      _cond.notify_one();
    };
    //TODO: remove in prod
    void test() {std::cout<<"Test from Message queue \n";};
  private:
    // TODO: internal counter? int _count;
    std::mutex mtx;
    std::deque<T> _queue;
    std::condition_variable _cond;
};

#endif
