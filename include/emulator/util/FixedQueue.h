#ifndef CPP_SP2_FIXEDQUEUE_H
#define CPP_SP2_FIXEDQUEUE_H

#include <queue>
#include <deque>

template <typename T, int MaxLen, typename Container=std::deque<T>>
class FixedQueue : public std::queue<T, Container> {
public:
    void push(const T& value) {
        if (this->size() == MaxLen) {
            this->c.pop_front();
        }
        std::queue<T, Container>::push(value);
    }
};

#endif //CPP_SP2_FIXEDQUEUE_H
