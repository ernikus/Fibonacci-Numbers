//Title:        Nth Fibonacci Number
//Difficulty:   Hard
//Source:       https://edabit.com/challenge/Y7DMN2uY8FL3czf8o
//Soln Author:	ernikus

#pragma once

#include <iostream>
#include <string>
#include <vector>


void reverseStr(std::string &str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		std::swap(str[i], str[n - i - 1]);
}

int char_to_int(const char character)
{
	return (int(character) - 48);
}

/*
std::string fibonacci(int n)
{
	static std::vector<std::string> numbers{ "0", "1" };
	const int limit = 201;

	if ((n-1) <= 1)
		return numbers[n-1];

	for (int i = 2; i <= limit; i++)
	{
		int size1 = numbers[i - 2].size();
		int size2 = numbers[i - 1].size();
		
		int size = size2;
		int diff = size - size1;

		std::cout << "Numer1: " << numbers[i - 2] << "\tNumber2: " << numbers[i - 1] << std::endl;
		std::cout << "Size1: " << size1 << "\tSize2: " << size2 << "\tHigh Size: " << size << "\tDiff: " << diff << std::endl;

		std::string result{};
		bool higher = false;

		for (int j = size-1; j >= 0; j--)
		{
			int trial{ 0 };


			if ((j - diff) >= 0)
			{
				trial = int(numbers[i - 2][j - diff])-48 + int(numbers[i - 1][j])-48;

				std::cout << "I.\tNum1: " << numbers[i - 2][j - diff] << "\tNum2: " << numbers[i - 1][j] << std::endl;
				std::cout << "II.\tNum1: " << int(numbers[i - 2][j - diff]) << "\tNum2: " << int(numbers[i - 1][j]) << std::endl;
			}
			else
			{
				trial = int(numbers[i - 1][j]) - 48;

				std::cout << "I.\tNum2: " << numbers[i - 1][j] << std::endl;
				std::cout << "II.\tNum2: " << int(numbers[i - 1][j]) << std::endl;
			}
				

			if (higher == true)
			{
				trial++;
				higher = false;
			}
			
			if (trial >= 10)
			{
				higher = true;
				trial -= 10;
			}

			result += std::to_string(trial);

			std::cout << "Trial: " << trial << "\tResult: " << result << "\tJ: " << j << std::endl;
		}

		if (higher == true)
		{
			result += "1";
			higher = false;
		}

		reverseStr(result);

		std::cout << i << ". " << result << std::endl;

		numbers.push_back(result);

		if (i == n )
			return numbers[i];
	}

	return "0";
}
*/

std::string fibonacci(int n)
{
	static std::string number[2]{ "0", "1" };

	const int limit = 11112;

	if ((n - 1) <= 1)
		return number[n - 1];

	for (static int i = 2; i <= limit; i++)
	{
		int size1 = number[0].size();
		int size2 = number[1].size();

		int size = size2;
		int diff = size - size1;

		//std::cout << "Numer1: " << number[0] << "\tNumber2: " << number[1] << std::endl;
		//std::cout << "Size1: " << size1 << "\tSize2: " << size2 << "\tHigh Size: " << size << "\tDiff: " << diff << std::endl;

		std::string result{};
		bool higher = false;

		for (int j = size - 1; j >= 0; j--)
		{
			int trial{ 0 };


			if ((j - diff) >= 0)
			{
				trial = char_to_int(number[0][j - diff]) + char_to_int(number[1][j]);

				//std::cout << "I.\tNum1: " << number[0][j - diff] << "\tNum2: " << number[1][j] << std::endl;
				//std::cout << "II.\tNum1: " << int(number[0][j - diff]) << "\tNum2: " << int(number[1][j]) << std::endl;
			}
			else
			{
				trial = char_to_int(number[1][j]);

				//std::cout << "I.\tNum2: " << number[1][j] << std::endl;
				//std::cout << "II.\tNum2: " << int(number[1][j]) << std::endl;
			}


			if (higher == true)
			{
				trial++;
				higher = false;
			}

			if (trial >= 10)
			{
				higher = true;
				trial -= 10;
			}

			result += std::to_string(trial);

			//std::cout << "Trial: " << trial << "\tResult: " << result << "\tJ: " << j << std::endl;
		}

		if (higher == true)
		{
			result += "1";
			higher = false;
		}

		reverseStr(result);

		//std::cout << i << std::endl;//". " << result << std::endl;

		number[0] = number[1];
		number[1] = result;

		if (i == n)
		{
			i++;
			return result;
		}
			
	}

	return "0";
}