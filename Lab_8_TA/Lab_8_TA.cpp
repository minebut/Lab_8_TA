#include <iostream>
#include <Windows.h>
#define N 5  

struct CircularQueue {
    int q[N];      
    int start;     
    int finish;    


    CircularQueue() : start(-1), finish(-1) {}

 
    bool isEmpty() const {
        return start == -1;
    }


    bool isFull() const {
        return (finish + 1) % N == start;
    }


    void push(int n) {
        if (isFull()) {
            std::cout << "Черга переповнена\n";
            return;
        }

        if (isEmpty()) { 
            start = 0;
        }

        finish = (finish + 1) % N; 
        q[finish] = n;
    }


    int pop() {
        if (isEmpty()) {
            std::cout << "Черга порожня\n";
            return -1;
        }

        int element = q[start];
        if (start == finish) { 
            start = -1;
            finish = -1;
        }
        else {
            start = (start + 1) % N;  
        }
        return element;
    }

    int front() const {
        if (!isEmpty())
            return q[start];
        std::cout << "Черга порожня\n";
        return -1;
    }

    int back() const {
        if (!isEmpty())
            return q[finish];
        std::cout << "Черга порожня\n";
        return -1;
    }

    int size() const {
        if (isEmpty())
            return 0;
        if (finish >= start)
            return finish - start + 1;
        return N - (start - finish - 1);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CircularQueue cq;
    for (int i = 0; i < N; i++) {
        cq.push(i);
    }
    std::cout << "Перший елемент: " << cq.front() << "\n";
    std::cout << "Останній елемент: " << cq.back() << "\n";
    std::cout << "Розмір черги: " << cq.size() << "\n";

    cq.pop();
    std::cout << "Перший елемент після видалення: " << cq.front() << "\n";
    std::cout << "Розмір черги після видалення: " << cq.size() << "\n";

    cq.push(5);
    std::cout << "Останній елемент після додавання: " << cq.back() << "\n";

    return 0;
}
