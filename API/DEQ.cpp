#include <algorithm>
#include "DEQ.h"
#include <stdexcept>

DEQ::DEQ(): size(0), top(nullptr), tail(nullptr) {}

DEQ::DEQ(const std::initializer_list<int> values) : DEQ()
{
    std::for_each(
        values.begin(),
        values.end(),
        [this](const int value) { this->PushFront(value); });
}

void DEQ::PushFront(const int value) {
    if (this->size == 0) {
        const auto item = new DEQElement(value, this->top, this->top);
        this->top = item;
        this->size++;
    }
    else {
        const auto item = new DEQElement(value, this->top, this->tail);
        this->top = item;
        this->tail = item;
        this->size++;
    }
}

void DEQ::PushBack(const int value) {
    const auto item = new DEQElement(value, this->tail, this->top);
    this->tail = item;
    this->size++;
}


int DEQ::PopFront() {
    if (this->isEmpty())
    {
        throw std::out_of_range("ДЭК пуст");
    }

    const auto value = this->top->value;

    const auto temp = this->top;
    this->top = top->next;
    this->size--;

    delete temp;
    return value;
}

int DEQ::PopBack() {
    if (this->isEmpty())
    {
        throw std::out_of_range("ДЭК пуст");
    }

    const auto value = this->tail->value;

    const auto temp = this->tail;
    this->tail = tail->prev;
    this->size--;

    delete temp;
    return value;
}

bool DEQ::isEmpty() const
{
    return this->GetSize() == 0;
}

std::size_t DEQ::GetSize() const
{
    return this->size;
}

DEQ::DEQElement::DEQElement(const int value, DEQElement* next, DEQElement* prev) :value(value), next(next), prev(prev)
{

}

DEQ::DEQElement::~DEQElement()
{
    this->next = nullptr;
}
