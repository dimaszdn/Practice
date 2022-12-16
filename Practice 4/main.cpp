#include<iostream>
#include<vector>

//Упаковать от 0 до 5 числа в 1 байт, получится в 2
//Функция добавления
//Функция извлечения

std::string binary(unsigned x)
{
    std::string s;
    do
    {
        s.push_back('0' + (x & 1));
    } while (x >>= 1);
    std::reverse(s.begin(), s.end());
    return s;
}

char packed(unsigned int begin, unsigned int lim)
{
    bool first = true;
    char r = 0;
    for (int i = begin; i <= lim; i++)
    {
        if (first)
        {
            r |= i;
            first = false;
        }
        else
        {
            r |= (i << binary(r).size());
        }
    }
    return r;
}

void extract(char r, std::vector<int>& v, unsigned int begin, unsigned int lim)
{
    r = static_cast<int>(r);
    bool first = true;
    int shift = 0;
    for (int i = begin; i <= lim; i++)
    {
        if (first)
        {
            v.push_back((r & i));
            first = false;
            shift += binary(i).size();
        }
        else
        {
            v.push_back((r >> shift) & i);
            shift += binary(i).size();
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    
    //Упаковали
    char pack1 = packed(0, 3);
    char pack2 = packed(4, 5);

    std::cout << "Как выглядит 1-ый пакет: " << pack1 << std::endl;
    std::cout << "\nРазмер 1-ого пакета: " << sizeof(pack1) << std::endl;

    std::cout << "\nКак выглядит 2-ой пакет: " << pack2 << std::endl;
    std::cout << "\nРазмер 2-ого пакета: " << sizeof(pack2) << std::endl;

    //Распаковали в вектор
    std::vector<int> numbers;
    extract(pack1, numbers, 0, 3);
    extract(pack2, numbers, 4, 5);
    std::cout << "\nВектор с извлеченными числами" << std::endl;
    for (int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

	return 0;
}