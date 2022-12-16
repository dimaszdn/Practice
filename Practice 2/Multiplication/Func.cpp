#include "Func.hpp"
#include<vector>
#include<string>

std::vector<int> transformation(std::string str)
{
	//Будем хранить большое число в векторе задом наперёд
	std::vector<int>bigInt;
	for (int i = str.size() - 1; i >= 0; i--)
		bigInt.push_back(static_cast<int>(str[i]) - 48);
	return bigInt;
}

int maxSize(int len1, int len2)
{
	if (len1 >= len2)
		return len1;
	else
		return len2;
}

void equal_length(std::vector<int>& v, int len)
{
	//Приводим к одной длине кратной 2
	while (len % 2 != 0)
	{
		len++;
	}
	v.resize(len);
}

std::vector<int> usualMul(std::vector<int>v1, std::vector<int>v2)
{
	std::vector<int>answer(v1.size() * 2);
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			answer[i + j] += v1[i] * v2[j];
		}
	}
	return answer;
}

std::vector<int> karatsubaMul(std::vector<int>v1, std::vector<int>v2)
{
	if (v1.size() <= 128)
	{
		return usualMul(v1, v2);
	}

	std::vector<int>answer(v1.size() * 2);
	int k = v1.size() / 2;
	
	//v1
	std::vector<int> P = { v1.begin(), v1.begin() + k };
	std::vector<int> Q = { v1.begin() + k, v1.end() };
	//v2
	std::vector<int> R = { v2.begin(), v2.begin() + k };
	std::vector<int> S = { v2.begin() + k, v2.end() };

	std::vector<int> Y = karatsubaMul(P, R);
	std::vector<int> Z = karatsubaMul(Q, S);

	std::vector<int>A(k);
	std::vector<int>B(k);
	//A = P + Q
	//B = R + S
	for (int i = 0; i < k; i++)
	{
		A[i] = P[i] + Q[i];
		B[i] = R[i] + S[i];
	}
	
	//X
	std::vector<int>X = karatsubaMul(A, B);

	//X - Y - Z
	for (int i = 0; i < v1.size(); i++)
	{
		X[i] -= Y[i] + Z[i];
	}

	//Собираем число конечное
	for (int i = 0; i < v1.size(); i++)
	{
		answer[i] = Y[i];
	}

	for (int i = v1.size(); i < 2 * v1.size(); i++)
	{
		answer[i] = Z[i - v1.size()];
	}
	
	for (int i = k; i < v1.size() + k; i++)
	{
		answer[i] += X[i - k];
	}

	return answer;
}

void remains(std::vector<int>& v)
{
	//Делаем переносы
	for (int i = 1; i < v.size(); i++)
	{
		v[i] += v[i - 1] / 10;
		v[i - 1] %= 10;
	}
}

void reSize(std::vector<int>& v, int len)
{
	while (v[len - 1] == 0)
	{
		len--;
	}
	v.resize(len);
}

void print(std::vector<int> v)
{
	reSize(v, v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		std::cout << v[i] << "";
}