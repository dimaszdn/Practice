#include<iostream>
#include<string>

int main()
{
	setlocale(LC_ALL, "RUS");
	
	std::string a;
	std::cout << "Введите первое число: ";
	std::cin >> a;

	std::string b;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	
	//Выравниваем длины чисел путём добавления нулей
	int size_a = a.size(), size_b = b.size();
	if (size_a > size_b)
	{
		while (size_b != size_a)
		{
			b = "0" + b;
			size_b++;
		}
	}
	else if (size_a < size_b)
	{
		while (size_a != size_b)
		{
			a = "0" + a;
			size_a++;
		}
	}
	//Добавим ещё по одному числу, т.к. при сложении в конце может получится остаток
	//который переходит в начало
	a = "0" + a;
	b = "0" + b;
	size_a++;
	size_b++;
	
	//Создадим динам. массив для хранения цифр числа1
	int* bigInt1 = new int[size_a]; 
	int j = 0;
	for (int i = size_a - 1; i >= 0; i--) //Задом наперёд получим цифры числа
	{
		bigInt1[j] = ((int)a[i] - 48);
		j++;
	}
	//Создадим динам. массив для хранения цифр числа2
	int* bigInt2 = new int[size_b]; 
	j = 0;
	for (int i = size_b - 1; i >= 0; i--)
	{
		bigInt2[j] = ((int)b[i] - 48);
		j++;
	}
	
	//Сумма больших чисел
	for (int i = 0; i < size_b; i++)
	{
		bigInt2[i] += bigInt1[i];
		bigInt2[i + 1] += (bigInt2[i] / 10);
		bigInt2[i] %= 10;
	}
	
	//Если не было остатка в конце и остался 0, уменьшим длину
	if (bigInt2[size_b - 1] == 0)
		size_b--;

	for (int i = size_b - 1; i >= 0; i--)
		std::cout << bigInt2[i] << "";

	delete[] bigInt1;
	delete[] bigInt2;

	return 0;
}