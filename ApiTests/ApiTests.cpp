#include "pch.h"
#include "CppUnitTest.h"
#include "../API/DEQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ApiTests
{
	TEST_CLASS(ApiTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const auto result = new DEQ();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(CtorWithInitializer_ValidData_Success) 
		{
			const size_t expectedSize = 5;

			DEQ result = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(expectedSize, result.GetSize());
			Assert::AreEqual(5, result.PopBack());
		}
	};
}
