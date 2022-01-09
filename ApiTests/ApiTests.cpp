#include "pch.h"
#include "CppUnitTest.h"
#include "../API/DEQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ApiTests
{
	TEST_CLASS(ApiTests)
	{
	public:
		
		TEST_METHOD(TestClassCreation)
		{
			const auto result = new DEQ();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(TestParamsClassCreate) 
		{
			const size_t expectedSize = 5;

			DEQ result = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(expectedSize, result.GetSize());
		}
		TEST_METHOD(TestPopBack)
		{
			DEQ result;
			Assert::ExpectException<std::out_of_range>([&]
				{
					result.PopBack(); //проверка на ошибку пустоты
				});
			result.PushBack(4);
			size_t expected = 1;
			Assert::AreEqual(expected, result.GetSize());
			Assert::AreEqual(4, result.PopBack()); // тест с 1м элементом в ДЭК
			expected = 0;
			Assert::AreEqual(expected, result.GetSize()); // тест на уменьшение размера
			result.PushFront(22);
			result.PushFront(42);
			Assert::AreEqual(22, result.PopBack()); // тест с несколькими элементами в ДЭК
			//Assert::AreEqual(1, result.PopBack());
		}
		TEST_METHOD(TestPopFront)
		{
			DEQ result;
			Assert::ExpectException<std::out_of_range>([&] 
				{
					result.PopFront(); //проверка на ошибку пустоты
				});

			result.PushFront(5);
			size_t expected = 1;
			Assert::AreEqual(expected, result.GetSize());
			Assert::AreEqual(5, result.PopFront()); // тест с 1м элементом в ДЭК
			expected = 0;
			Assert::AreEqual(expected, result.GetSize()); // тест на уменьшение размера
			result.PushFront(22);
			result.PushFront(42);
			Assert::AreEqual(42, result.PopFront()); // тест с несколькими элементами в ДЭК
			
		}
		TEST_METHOD(TestPushBack)
		{
			DEQ result;
			size_t expected = 0;
			Assert::AreEqual(expected, result.GetSize());
			result.PushBack(30);
			expected = 1;
			Assert::AreEqual(expected, result.GetSize()); // проверка на увеличение размера
			Assert::AreEqual(30, result.PopBack()); // проверка с 1м элементом
			result.PushBack(50);
			result.PushBack(10);
			Assert::AreEqual(10, result.PopBack()); // проверка с несколькими элементами
		}
		TEST_METHOD(TestPushFront)
		{	
			DEQ result;
			size_t expected = 0;
			Assert::AreEqual(expected, result.GetSize());
			result.PushFront(50);
			expected = 1;
			Assert::AreEqual(expected, result.GetSize()); // проверка на увеличение размера
			Assert::AreEqual(50, result.PopFront()); // проверка с 1м элементом
			result.PushFront(30);
			result.PushFront(2);
			Assert::AreEqual(2, result.PopFront()); // проверка с несколькими элементами
		}
		TEST_METHOD(TestGetSize)
		{
			size_t expected = 0;
			DEQ result;
			Assert::AreEqual(expected, result.GetSize());
			result.PushFront(42);
			expected = 1;
			Assert::AreEqual(expected, result.GetSize());
		}
		TEST_METHOD(TestIsEmpty)
		{
			DEQ result;
			Assert::IsTrue(result.isEmpty());
			result.PushFront(2);
			Assert::IsFalse(result.isEmpty());
		}
	};
}
