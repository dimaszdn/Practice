#include<iostream>
#include<vector>

namespace ch
{
	class Vector
	{
	
	private:
		int* vec;
		size_t m_sz;
		size_t m_cap;
	
	public:
		Vector()
		{
			m_cap = 1;
			m_sz = 0;
			vec = new int[1];
		}
		~Vector()
		{
			delete[] vec;
		}

		//Вернуть длину
		size_t size() const
		{
			return m_sz;
		}

		//Вернуть кол-во места
		size_t capacity() const
		{
			return m_cap;
		}

		//Увеличить количество места
		void reserve(size_t cap)
		{
			if (cap <= m_cap)
				return;

			int* tmp = new int[cap];
			for (int i = 0; i < m_sz; ++i)
			{
				tmp[i] = vec[i];
			}
			delete[] vec;
			m_cap = cap;
			vec = tmp;
		}

		//Добавить элемент в конец
		void push_back(int el)
		{
			if (m_cap > m_sz)
			{
				vec[m_sz] = el;
				++m_sz;
				return;
			}
			reserve(2 * m_sz);
			vec[m_sz] = el;
			++m_sz;
		}

		//Распечатать вектор
		void print()
		{
			for (int i = 0; i < m_sz; ++i)
				std::cout << vec[i] << " ";
			std::cout << std::endl;
		}

		//Вернуть элемент
		int returnEl(unsigned int i)
		{
			return vec[i];
		}

		//Изменить элемент
		void changeEl(unsigned int i, int el)
		{
			vec[i] = el;
		}

		//Вставить элемент по индексу
		void addEl(unsigned int index, int el)
		{
			if (m_cap == m_sz)
			{
				reserve(2 * m_sz);
			}
			++m_sz;
			for (int i = m_sz - 1; i >= index; --i)
			{
				vec[i] = vec[i - 1];
			}
			vec[index] = el;
		}

		//Удалить элемент по индексу
		void erase(unsigned int index)
		{
			for (int i = index + 1; i <= m_sz; ++i)
			{
				vec[i - 1] = vec[i];
			}
			--m_sz;
		}
	};
}

/*
Что умеет вектор:
вывод +
1) Добавлять элемент в конец +
2) Выдавать текущее кол-во эл-ов +
	2.1 capacity +
3) Выдавать эл. по индексу +
4) Изменять эл. по индексу +
5) Удалять эл. по индексу +
6) Вставлять эл. по индексу +
*/

int main()
{
	ch::Vector v;
	srand(time(0));
	for (int i = 0; i < 7; i++)
		v.push_back(rand() % 100);
	v.print();

	std::cout << v.size() << "\n\n";

	std::cout << v.capacity() << "\n\n";

	std::cout << v.returnEl(4) << "\n\n";

	v.changeEl(3, 1000);
	v.print();

	std::cout << "\n";
	v.erase(3);
	v.print();

	std::cout << "\n";
	v.addEl(3, 500);
	v.print();

	return 0;
}