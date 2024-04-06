#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>
#include <chrono>
const int array_size = 1000000;

template <typename T>
struct stack_mass {
    T* hop;
    T mass[array_size];
    int count_of_elm = 0;


    void add_element(T elm)
    {
        if (count_of_elm == 0)
        {
            mass[0] = elm;
            hop = &mass[0];
            count_of_elm++;
        }
        else
        {
        if(count_of_elm <= array_size)
        {
            hop++;
            *hop = elm;
            count_of_elm++;
        }
        else
        {
            std::cout << "Ошибка. Переполнение стека.\n";
        }
        }


    }

        T get_element()
        {
            if (count_of_elm == 0)
            {
                std::cout << "Стек пуст";
                return -1;
            }
            else
            {
                if(count_of_elm == 1)
                {

                    hop = nullptr;
                    count_of_elm--;
                    return mass[0];
                }
                else
                {
                    T elm = *hop;
                    hop--;
                    count_of_elm--;
                    return elm;
                }
            }
        };
    

};

int main()
{   
    stack_mass<int> stack_arr;
    for (int i=0; i<10000; i++)
    {
        stack_arr.add_element(i);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<10000; i++)
    {
    stack_arr.get_element();
    }

    // Замер времени после выполнения кода
    auto end = std::chrono::high_resolution_clock::now();

    // Вычисление времени выполнения
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(end - start);

    // Вывод времени выполнения
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0;

    
    
    
}