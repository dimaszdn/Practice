#include<iostream>
#include<vector>

int main()
{
	//push_back
	std::vector<int>v;
	srand(time(0));
	std::cout << "push_back" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(rand() % 100);
		std::cout << v[i] << " ";
	}
	std::cout << std::endl << std::endl;

	//insert
	/*Добавляет элемент по индексу. Но в качестве индекса выступает
	не обычное число как раньше, а итератор*/

	std::vector<int>::iterator itInsert = v.begin();
	v.insert(itInsert + 4, 1000);

	std::cout << "insert" << std::endl;
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;
	
	//erase
	/*Удаляет элемент по индексу. Но в качестве индекса выступает
	снова итератор*/
	
	std::vector<int>::iterator itErase = v.begin();
	v.erase(itErase + 4);

	std::cout << "erase" << std::endl;
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;

	//emplace_back
	/*В отличии от push_back эта функция вставляет объект в вектор
	напрямую без вызова конструктора копирования*/
	
	v.emplace_back(500);
	std::cout << "emplace_back" << std::endl;
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;

	//resize
	/*Уменьшает или увеличивает длину вектора*/
	v.resize(5);
	std::cout << "resize" << std::endl;
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;

	//capacity
	/*Возвращает ёмкость вектора, т.е кол-во элементов, которое
	мы можем положить в вектор*/
	std::cout << "capacity" << std::endl;
	std::cout << v.capacity() << std::endl << std::endl;

	//reserve
	/*Ёмкость вектора каждый раз автоматически растёт, если нет места под новый 
	элемент. При помощи функции reserve мы можем сами устанавливать ёмкость вектора*/
	v.reserve(20);
	std::cout << "reserve" << std::endl;
	std::cout << v.capacity() << std::endl << std::endl;

	//shrink_to_fit
	/*Если у нас из всей ёмкости вектора используется лишь элементов 10, а ёмкость
	составляет, например, 100, то мы просто так занимаем память. Эта
	функция позволяет сократить общую ёмкость до той, которая используется*/
	v.shrink_to_fit();
	std::cout << "shrink_to_fit" << std::endl;
	std::cout << v.capacity() << std::endl << std::endl;

	/*Вектор тот же массив, поэтому можно использовать [], чтобы обратиться
	к его конкретному элементу*/
	std::cout << v[3] << std::endl;
	v[3] = 2345;
	std::cout << v[3] << std::endl << std::endl;

	//clear
	/*Очищает вектор*/
	v.clear();
	
	std::vector<int>vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(rand() % 50);
	}
	std::cout << std::endl;

	//Чтобы узнать сколько места занимает вектор нужно знать:
	//1)Где он начинается
	//2)Где он заканчивается по длине
	//3)Где он заканчивается с учётом резервного места
	int* p1 = &vec[vec.size() - 1];
	int* p2 = &vec[0];
	//Это, если вектор выделяет новое место, когда size > capacity
	vec.resize(vec.capacity()); // size = capacity
	int* p3 = &vec[vec.size() - 1];
	
	std::cout << "Возможный размер: " << sizeof(p1) + sizeof(p2) + sizeof(p3); //+ издержки
	return 0;
}