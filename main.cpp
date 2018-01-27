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
    bool vihod = true;
    while (vihod) {
        menu();
        cin >> choise;
        switch (choise) {
            case 1: list_show(list);
            break;
            case 2: add_elements(list);
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:  
                cout << "Вы хотите выйти из программы?" << endl;
                string answer;
                cin >> answer;
                if ((answer == "yes") || (answer == "y") || (answer == "Y") || (answer == "Yes") || (answer == "YES"))
                    vihod = false;
                else
                if ((answer == "no") || (answer == "n") || (answer == "N") || (answer == "No") || (answer == "NO"))
                    vihod == true;
            break;
            return 0;
            default: cout << "Неверная команда" << endl;
        }
    }
}
