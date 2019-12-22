#include "pch.h"
#include "CppUnitTest.h"
#include "../ISBN13/isbn13.h"
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeTest
{
	TEST_CLASS(NativeTest)
	{
	public:
		
		TEST_METHOD(TestSetBase)
		{
			ISBN13 object;

			std::string line;
			std::ifstream myfile("TestData.txt");
			Assert::IsTrue(myfile.is_open());
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					auto output = ISBN13::Complete(line);

					std::cout << line << '\n';
				}
				myfile.close();
			}

			else std::cout << "Unable to open file";

		}
	};
}
