#include <algorithm>
#include "DEQ.h"
#include <stdexcept>

DEQ::DEQ(): size(0), head(nullptr), tail(nullptr) {}

DEQ::DEQ(const std::initializer_list<int> values) : DEQ()
{
    std::for_each(
        values.begin(),
        values.end(),
        [this](const int value) { this->PushFront(value); });
}

DEQ::~DEQ()
{
    while (this->head)
    {
        auto temp = head->next;
        delete head;
        head = temp;
    }
}

void DEQ::PushFront(const int value) {
    const auto temp = new DEQElement(value, this->head, this->head);
    temp->next = nullptr;
    temp->value = value;
    if (head != nullptr) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else {
        temp->prev = nullptr;
        head = tail = temp;
    }
    this->size++;
}

void DEQ::PushBack(const int value) {
    const auto temp = new DEQElement(value, this->tail, this->head);
    temp->prev = nullptr;
    temp->value = value;
    if (head != nullptr) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else {
        temp->next = nullptr;
        tail = head = temp;
    }
    this->size++;
}


int DEQ::PopBack() {
    if (this->isEmpty())
    {
        throw std::out_of_range("ДЭК пуст");
    }

    const auto value = this->head->value;

    const auto temp = this->head;
    this->head = head->next;
    this->size--;
    this->head->prev = nullptr;
    delete temp;
    return value;
}

int DEQ::PopFront() {
    if (this->isEmpty())
    {
        throw std::out_of_range("ДЭК пуст");
    }

    const auto value = this->tail->value;

    const auto temp = this->tail;
    this->tail = tail->prev;
    this->size--;
    this->tail->next = nullptr;
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
    this->prev = nullptr;
}
