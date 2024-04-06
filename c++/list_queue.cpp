#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>
#include <chrono>
using namespace std;
const int array_size = 1000000;



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
    if (head == NULL) {
        return NULL;  // Возвращаем NULL, если список пуст
    } else {
        Node* temp = head;
        head = head->next;  // Перемещаем указатель head на следующий элемент
        temp->next = NULL;  // Отсоединяем извлеченный элемент от списка
        return temp;
    }
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
    








