#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

template <class T>
class MessageQueue {
  public:
    T receive();
    void send(T &&message);
  private:
    int _count;
};

#endif
