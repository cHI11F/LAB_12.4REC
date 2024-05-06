#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createList(int values[], int size, int index = 0) {
    if (index >= size) {
        return nullptr;
    }

    // Створення нового вузла
    Node* newNode = new Node();
    newNode->data = values[index];
    newNode->prev = nullptr;
    newNode->next = createList(values, size, index + 1);

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }

    return newNode;
}

// Функція для визначення, чи список містить пару сусідніх елементів з однаковими значеннями
bool containsAdjacentDuplicates(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    if (head->data == head->next->data) {
        return true;
    }

    return containsAdjacentDuplicates(head->next);
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }

    cout << head->data << " ";
    printList(head->next);
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }

    deleteList(head->next);
    delete head;
}

int main() {

    int values[] = { 1, 2, 2, 3, 4, 5, 5, 6, 7 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    // Перевірка наявності пари сусідніх елементів з однаковими значеннями
    if (containsAdjacentDuplicates(head)) {
        cout << "У списку є пара сусідніх елементів з однаковими значеннями." << endl;
    }
    else {
        cout << "У списку немає пари сусідніх елементів з однаковими значеннями." << endl;
    }

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
