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
	DEQ(const std::initializer_list<int> values);
	/**
	* \brief Деструктор по-умолчанию
	*/
	~DEQ();
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
	bool isEmpty() const;
	/**
	* \brief Получить размер ДЭК
	*/
	std::size_t GetSize() const;

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
		DEQElement(int value, DEQElement* next = nullptr, DEQElement* prev = nullptr);
		~DEQElement();

		int value;
		DEQElement* next;
		DEQElement* prev;
	};
	
	size_t size;

	DEQ(const DEQ& rhs);
	DEQElement* head;
	DEQElement* tail;

	DEQ operator= (const DEQ& rhs);
};
