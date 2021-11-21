#pragma once
#include <initializer_list>

/*!
Класс ДЭК для хранения целых чисел
*/
class DEQ
{
public:
	/*!
	Конструктор по-умолчанию
	*/
	DEQ();
	/*!
	Создание объекта из последовательности
	*/
	DEQ(std::initializer_list<int> value);
	/*!
	Добавление элемента в ДЭК в начало
	*/
	void PushFront(const int value);
	/*!
	Добавление элемента в ДЭК в конец
	*/
	void PushBack(const int value);
	/*!
	Удаление элемента с начала
	*/
	int PopFront();
	/*!
	Удаление элемента с конца
	*/
	int PopBack();
	/*!
	Проверка ДЭК на пустоту
	*/
	bool isEmpty();
	/*!
	Деструктор по-умолчанию
	*/
	~DEQ();

private:
	/*!
	Элементы ДЭК для хранения целых чисел
	*/
	class DEQElement
	{
	public:
		/*!
		Конструктор по-умолчанию
		*/
		DEQElement();
		/*!
		Конструктор с параметрами
		value Целое значение.
		*/
		DEQElement(int value);
		~DEQElement();

	private:
		int value;
		DEQElement* next;
	};
	DEQElement* top;
	DEQElement* tail;
};
