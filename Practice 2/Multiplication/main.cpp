#include<iostream>
#include "Func.hpp"
#include<vector>
#include<string>

int main()
{
	setlocale(LC_ALL, "RUS");
	
	std::cout << "Введите первое число: ";
	std::string a;
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::string b;
	std::cin >> b;

	if ((a == "0") || (b == "0"))
		std::cout << "\nОтвет: " << 0 << std::endl;
	else
	{
		std::vector<int>bigInt1 = transformation(a);
		std::vector<int>bigInt2 = transformation(b);
		int n = maxSize(bigInt1.size(), bigInt2.size());
		equal_length(bigInt1, n);
		equal_length(bigInt2, n);

		std::vector<int>res = usualMul(bigInt1, bigInt2);
		remains(res);
		std::cout << "\nОтвет: ";
		print(res);
	}

	return 0;
}