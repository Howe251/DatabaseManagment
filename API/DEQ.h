#pragma once
#include <initializer_list>

/**
* \brief Класс ДЭК для хранения целых чисел
*/
class DEQ
{
public:
	/**
	* \brief Конструктор по-умолчанию
	*/
	DEQ();
	/**
	* \brief Создание объекта из последовательности
	*/
	DEQ(std::initializer_list<int> value);
	/**
	* \brief Добавление элемента в ДЭК в начало
	* \param value целое число
	*/
	void PushFront(const int value);
	/**
	* \brief Добавление элемента в ДЭК в конец
	* \param value целое число
	*/
	void PushBack(const int value);
	/**
	* \brief Удаление элемента с начала
	*/
	int PopFront();
	/**
	* \brief Удаление элемента с конца
	*/
	int PopBack();
	/**
	* \brief Проверка ДЭК на пустоту
	*/
	const bool isEmpty();
	/**
	* \brief Деструктор по-умолчанию
	*/
	~DEQ();

private:
	/**
	* \brief Элементы ДЭК для хранения целых чисел
	*/
	class DEQElement
	{
	public:
		/**
		* \brief Конструктор по-умолчанию
		*/
		DEQElement();
		/**
		* \brief Конструктор с параметрами
		* \param value Целое значение.
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
