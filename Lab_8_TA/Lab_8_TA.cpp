#include <iostream>
#include <Windows.h>

const int N = 10;
struct Queue {
    int q[N];
    int start, finish;

    Queue() : start(0), finish(0) {}

    void push(int n) {
        if (size() == N - 1) {
            std::cout << "Черга переповнена\n";
            return;
        }
        q[finish] = n;
        finish = (finish + 1) % N;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Черга порожня\n";
            return -1;
        }
        int a = q[start];
        start = (start + 1) % N;
        return a;
    }

    bool isEmpty() const {
        return start == finish;
    }

    int size() const {
        return (finish + N - start) % N;
    }

    void clear() {
        start = 0;
        finish = 0;
    }

    int front() const {
        if (!isEmpty())
            return q[start];
        std::cout << "Черга порожня\n";
        return -1;
    }

    int back() const {
        if (!isEmpty())
            return q[(finish + N - 1) % N];
        std::cout << "Черга порожня\n";
        return -1;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue q;

    for (int i = 1; i < N; i++) {
        q.push(i);
    }
    std::cout << "Перший елемент " << q.front() << "\n";
    std::cout << "Останній елемент " << q.back() << "\n";
    std::cout << "Розмір черги " << q.size() << "\n";

    std::cout << "Видаляємо елемент " << q.pop() << "\n";
    std::cout << "Розмір черги після видалення " << q.size() << "\n";

    return 0;
}
