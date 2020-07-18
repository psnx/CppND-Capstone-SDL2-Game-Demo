#include <mutex>

#include "MessageQueue.h"

template<typename T>
T MessageQueue<T>::receive() {
    return nullptr;

}

template<typename T>
void MessageQueue<T>::send(T &&message) {

}