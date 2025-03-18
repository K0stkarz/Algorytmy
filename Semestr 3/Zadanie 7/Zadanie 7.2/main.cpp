#include <cassert>
#include "arraystack.h"

int main() {
    // Tworzenie stosu z pojemnością 5
    ArrayStack<int, 5> stack;

    // Test: początkowy stan stosu
    assert(stack.empty());
    assert(!stack.full());
    assert(stack.size() == 0);
    assert(stack.max_size() == 5);

    // Test: dodawanie elementów za pomocą push()
    stack.push(10);
    stack.push(20);
    stack.push(30);
    assert(!stack.empty());
    assert(stack.size() == 3);
    assert(stack.top() == 30); // Sprawdzenie wartości na wierzchu stosu

    // Test: pop()
    stack.pop();
    assert(stack.size() == 2);
    assert(stack.top() == 20);

    // Test: push() z przenoszeniem
    int value = 40;
    stack.push(std::move(value));
    assert(stack.size() == 3);
    assert(stack.top() == 40);

    // Test: przepełnienie stosu
    stack.push(50);
    stack.push(60);
    try {
        stack.push(70); // Próba dodania elementu do pełnego stosu
        assert(false); // Nie powinno dojść tutaj
    } catch (const std::overflow_error&) {
        assert(true); // Oczekiwany wyjątek
    }

    // Test: dostęp do top() na pustym stosie
    stack.clear();
    try {
        stack.top(); // Próba dostępu do wierzchu pustego stosu
        assert(false); // Nie powinno dojść tutaj
    } catch (const std::underflow_error&) {
        assert(true); // Oczekiwany wyjątek
    }

    // Test: pop() na pustym stosie
    try {
        stack.pop(); // Próba usunięcia elementu z pustego stosu
        assert(false); // Nie powinno dojść tutaj
    } catch (const std::underflow_error&) {
        assert(true); // Oczekiwany wyjątek
    }

    // Test: clear()
    stack.push(100);
    stack.push(200);
    stack.clear();
    assert(stack.empty());
    assert(stack.size() == 0);

    // Test: przenoszenie stosu
    ArrayStack<int, 5> stack2(std::move(stack));
    assert(stack.empty()); // Stary stos powinien być pusty
    assert(stack2.empty()); // Nowy stos również powinien być pusty

    // Test: przypisanie kopiujące
    stack2.push(10);
    stack2.push(20);
    ArrayStack<int, 5> stack3;
    stack3 = stack2;
    assert(stack3.size() == stack2.size());
    assert(stack3.top() == stack2.top());

    // Test: przypisanie przenoszące
    ArrayStack<int, 5> stack4;
    stack4 = std::move(stack2);
    assert(stack2.empty());
    assert(stack4.size() == 2);
    assert(stack4.top() == 20);

    // Test: display()
    stack4.display(); // Powinno wyświetlić elementy stosu w konsoli

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
