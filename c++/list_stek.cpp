#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>
#include <chrono>
const int array_size = 1000000;

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;  // Глобальная переменная, указывающая на начало списка

void add_element(int value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

Node* get_element() {
    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Теперь temp указывает на последний элемент, а prev - на предпоследний
    // Удалите последний элемент и освободите память
    if (prev == NULL) {
        head = NULL;  // Если в списке только один элемент
    } else {
        prev->next = NULL;
    }
    return temp;
}




int main() {


    // add_element(5);
    // add_element(10);
    // add_element(15);

    for (int i=0; i<500; i++)
    {
        add_element(i);
    }
auto start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<500; i++)
    {
   
    Node* extracted_element = get_element();
    // cout << "Извлеченный элемент: " << extracted_element->data << endl;

    // Освободите память для извлеченного элемента
    delete extracted_element;
    }


    // Замер времени после выполнения кода
    auto end = std::chrono::high_resolution_clock::now();

    // Вычисление времени выполнения
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(end - start);

    // Вывод времени выполнения
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;


    return 0;
}
