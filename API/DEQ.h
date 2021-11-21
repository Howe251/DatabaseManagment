#pragma once
#include <initializer_list>

/*!
����� ��� ��� �������� ����� �����
*/
class DEQ
{
public:
	/*!
	����������� ��-���������
	*/
	DEQ();
	/*!
	�������� ������� �� ������������������
	*/
	DEQ(std::initializer_list<int> value);
	/*!
	���������� �������� � ��� � ������
	*/
	void PushFront(const int value);
	/*!
	���������� �������� � ��� � �����
	*/
	void PushBack(const int value);
	/*!
	�������� �������� � ������
	*/
	int PopFront();
	/*!
	�������� �������� � �����
	*/
	int PopBack();
	/*!
	�������� ��� �� �������
	*/
	bool isEmpty();
	/*!
	���������� ��-���������
	*/
	~DEQ();

private:
	/*!
	�������� ��� ��� �������� ����� �����
	*/
	class DEQElement
	{
	public:
		/*!
		����������� ��-���������
		*/
		DEQElement();
		/*!
		����������� � �����������
		value ����� ��������.
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
