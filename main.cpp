#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int const length = 4;
int count = 0, First, Last = 0;
int queue[length] {};

bool IsNum(string const& check)
{
    if (check.empty()) return false;
    size_t startPos = (check[0] == '-') ? 1 : 0;
    return check.find_first_not_of("0123456789", startPos) == string::npos;
}

bool IsEmpty()
{
    return count == 0;
}

bool IsFull()
{
    return count == length;
}

void Push(int num)
{
    if(!IsFull())
    {
        if (Last != length)
        {
            queue[Last] = num;
            Last++;
            count++;
        }
        else
        {
            Last = 0;
            queue[Last] = num;
            Last++;
            count++;
        }
    }
    else
    {
        cout << "Очередь полна\n";
    }
}

void Pop()
{
    if (!IsEmpty())
    {
        if(First != length)
        {
            queue[First] = NULL;
            First++;
            count--;
        }
        else
        {
            First = 0;
            queue[First] = NULL;
            First++;
            count--;
        }
        cout << "Элемент удалён\n";
    }
    else
    {
        cout << "Очередь пуста\n";
    }
}

void PrintQue()
{
    if (!IsEmpty())
    {
        cout << "Состояние очереди: ";
        for(int el : queue)
        {
            if (el != NULL)
            {
                cout << el << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Очередь пуста\n";
    }
}

void Print()
{
    if (!IsEmpty())
    {
        cout << "Очередь: ";
        for (int i = First; i < length; i++)
        {
            if (queue[i] != NULL) { cout << queue[i] << " "; }
        }
        for (int i = 0; i < First; i++)
        {
            if (queue[i] != NULL) { cout << queue[i] << " ";}
        }
        cout << endl;
    }
    else
    {
        cout << "Очередь пуста\n";
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string dialog;
    bool flag = true;
    std::string menu =
                        "1 - Очередь пуста?\n"
                        "2 - Очередь полна?\n"
                        "3 - Добавить новый элемент\n"
                        "4 - Удалить элемент\n"
                        "5 - Вывести очередь\n"
                        "6 - Вывести текущее состояние очереди\n"
                        "0 - Завершение программы\n";
    std::cout << menu;
    cin >> dialog;
    while(flag)
    {
        if (IsNum(dialog))
        {
            switch (stoi(dialog))
            {
                case 1:
                    if (IsEmpty())
                    {
                        cout << "Очередь пуста\n";
                    }
                    else
                    {
                        cout << "Очередь не пуста\n";
                    }
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 2:
                    if (IsFull())
                    {
                        cout << "Очередь полна\n";
                    }
                    else
                    {
                        cout << "Очередь не полна\n";
                    }
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 3:
                    cout << "Введите число: ";
                    cin >> dialog;
                    while(!IsNum(dialog))
                    {
                        cout << "Неверный ввод чилсла. Повторите ввод\n";
                        cin >> dialog;
                    }
                    Push(stoi(dialog));
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 4:
                    Pop();
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 5:
                    Print();
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 6:
                    PrintQue();
                    std::cout << menu;
                    cin >> dialog;
                    break;
                case 0:
                    flag = false;
                    break;
                default:
                    cout << "Несуществующая команда. Повторите ввод.\n";
                    std::cout << menu;
                    cin >> dialog;
            }
        }
        else
        {
            cout << "Неверная команда. Повторите ввод.\n";
            std::cout << menu;
            cin >> dialog;
        }
    }

    return 0;
}
