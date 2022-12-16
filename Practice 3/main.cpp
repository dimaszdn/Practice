#include<iostream>
#include<fstream>
#include<string>

//Проверка на вхождение
bool letter_empty(std::string tmp, wchar_t a)
{
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tolower(a) == tolower(tmp[i]))
			return false;
	}
	return true;
}

//Выделяем неодинаковые буквы
std::string noRepetitions(std::string str)
{
	std::string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (letter_empty(tmp, (wchar_t)str[i]))
		{
			tmp += toupper((wchar_t)str[i]);
		}
		else
		{
			tmp += str[i];
		}
	}
	return tmp;
}

//Подсчитываем кол-во выделенных букв
int countBigLetters(std::string str)
{
	std::string ABC = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	int k = 0;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < ABC.size(); j++)
		{
			if (str[i] == ABC[j])
			{
				k++;
			}
		}
	}
	return k;
}

//Проверка на знак препинания
bool punct_marks(std::string str)
{
	int mas[10] = { 33, 34, 39, 40, 41, 44, 45, 46, 58, 59 };
	for (int i = 0; i < 10; i++)
	{
		if (str[str.size() - 1] == mas[i])
			return true;
	}
	return false;
}

//Вытаскиваем выделенные буквы
std::string bigLetters(std::string str)
{
	std::string tmp = "";
	std::string ABC = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < ABC.size(); j++)
		{
			if (str[i] == ABC[j])
			{
				tmp += str[i];
			}
		}
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	std::ifstream fin("input.txt", std::ios::in);
	std::ofstream fout("output.txt", std::ios::out);
	
	
	if (!fin.is_open())
		std::cout << "Не удалось открыть файл!" << std::endl;
	else
	{
		std::cout << "Файл успешно открыт!" << std::endl;
		while (!fin.eof())
		{
			std::string word = "";
			fin >> word;
			if (word.size() >= 7)
			{
				std::string newWord = noRepetitions(word);
				if (countBigLetters(newWord) >= 7)
				{
					if (punct_marks(newWord))
					{
						char punct = newWord[newWord.size() - 1];
						newWord.erase(newWord.size() - 1);
						fout << newWord << " (" << bigLetters(newWord) << ")" << punct << " ";
					}
					else
						fout << newWord << " (" << bigLetters(newWord) << ")" << " ";
				}
				else
					fout << word << " ";
			}
			else
				fout << word << " ";
		}
	}

	return 0;
}