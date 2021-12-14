#include <algorithm>
#include "DEQ.h"

#include <stdexcept>

DEQ::DEQ() :size(0), top(nullptr), {}

DEQ::PushFront(int value) {
    const auto item = new StackElement(value, this->top);
    this->top = item;
    this->size++;
}
