#include<iostream>
#include<locale>
#include<string>

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
    Node *next;
};
struct List {
    Node *head;
    Node *last;
};

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

void list_show(List list) {
    while (list.head != nullptr) {
        cout << list.head -> data;
        if (list.head -> next != nullptr)
            cout << "->";
        list.head = list.head -> next;
    }
    cout << endl;
}

void add_elements(List &list) {
    int k = 0;
    cout << "Введите количество элементов" << endl;
    cin >> k;
    int *dop_mass = new int [k];
    cout << "Введите элементы" << endl;
    for (int i=0; i<k; i++) 
        cin >> dop_mass[i];
    for (int i=0; i<k; i++) {
        Node *node = new Node;
        node -> data = dop_mass[i];
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

void delete_element(List &list) {
    if (list.head == nullptr) {
        return;
    }
    int deleted_element = 0;
    cout << "Введите значение элемента" << endl;
    cin >> deleted_element;
    Node *node = list.head;
    if (node -> data == deleted_element) {
        list.head = node -> next;
        delete node;
        return;
    }
    Node *node1 = node -> next;
    while (node1) {
        if (node1 -> data == deleted_element) {
            node -> next = node1 -> next;
            delete node1;
            return;
        }
        node = node1;
        node1 = node1 -> next;
    }
    if (deleted_element != node -> data)
        cout << "Элемент " << deleted_element << " отсутсвует" << endl;
}

void search_position(List &list) {
    int value = 0;
    cout << "Введите значение элемента" << endl;
    cin >> value;
    int position = 0;
    Node *node = list.head;
    while (node) {
        if (node -> data == value) {
            cout << "Позиция = " << position << endl;
        }
        else position++;
        node = node -> next;
    }
}

void replacement_value(List &list) {
    int position, new_value, count = 0;
    cout << "Введите позицию и новое значение" << endl;
    cin >> position >> new_value;
    Node *node = list.head;
    while (node) {
        if (count == position) 
            node -> data = new_value;
        node = node -> next;
        count++;
    }
}

void sort_etems(List &list, int *&mass, int n) {
    Node *node = list.head;
    for (int i=0; i<n; i++) {
        mass[i] = node -> data;
        node = node -> next;
    }
    int temp = 0;
    for (int i=0; i<n; i++) {
        for (int j=(n-1); j>=(i+1); j--) {
            if (mass[j] < mass[j-1]) {
                temp = mass[j];
                mass[j] = mass[j-1];
                mass[j-1] = temp;
            }
        }
    }
    node = list.head;
    for (int i=0; i<n; i++) {
        node -> data = mass[i];
        node = node -> next;
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
    int *dop_mass = nullptr;
    int k;   
    create_list(list, mass, n);
    int choise;
    bool exit = true;
    while (exit) {
        menu();
        cin >> choise;
        switch (choise) {
            case 1: list_show(list);
            break;
            case 2: add_elements(list);
            break;
            case 3: delete_element(list);
            break;
            case 4: search_position(list);
            break;
            case 5: replacement_value(list);
            break;
            case 6: sort_etems(list, mass, n);
            break;
            case 7:  
                cout << "Вы хотите выйти из программы?" << endl;
                string answer;
                cin >> answer;
                if ((answer == "yes") || (answer == "y") || (answer == "Y") || (answer == "Yes") || (answer == "YES"))
                    exit = false;
                else
                if ((answer == "no") || (answer == "n") || (answer == "N") || (answer == "No") || (answer == "NO"))
                    exit == true;
            break;
            return 0;
            default: cout << "Неверная команда" << endl;
        }
    }
}
