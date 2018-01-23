#include<iostream>
#include<locale>

using namespace std;

void menu() {
    cout << "Выберите одну из операций" << endl;
    cout << "1.Распечатать список" << endl;
    cout << "2.Добавить элементы в список" << endl;
    cout << "3.Удалить элемент" << endl;
    cout << "4.Найти позиции элементов" << endl;
    cout << "5.Заменить эелемент на другой" << endl;
    cout << "6.Отсортировать элементы списка" << endl;
    cout << "7.Завершить работу программы" << endl;
}

struct Node {
    int data;
    Node *last;
    Node *next;
};
struct List {
    Node *head;
    Node *last;
};

void list_show(List list) {
    while (list.head != nullptr) {
        cout << list.head -> data;
        if (list.head -> next != nullptr)
            cout << "->";
        list.head = list.head -> next;
    }
    cout << endl;
}
void create_list(List &list, int *&mass, int n) {
    for (int i=0; i<n; i++) {
        Node *node = new Node;
        node -> data = mass[i];
        node -> next = nullptr;
        if (list.last == nullptr) {
            list.last = node;
            list.head = list.last;
            continue;
        }
        list.last -> next = node;
        list.last = node;
    }
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    List list;
    list.head = nullptr;
    list.last = nullptr;
    int n = 0;
    cout << "Введите количество элементов" << endl;
    cin >> n;
    int *mass = new int[n];
    cout << "Введите элементы" << endl;
    for (int i=0; i<n; i++) 
        cin >> mass[i];
        
    create_list(list, mass, n);
    int choise;
    while (true) {
        menu();
        cin >> choise;
        switch (choise) {
            case 1: list_show(list);
            break;
            return 0;
            default: cout << "Неверная команда" << endl;
        }
    }
}
