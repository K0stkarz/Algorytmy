#include <iostream>
#include <cassert>
#include "A.hpp"  // Załóżmy, że to jest nasz plik nagłówkowy z implementacją SetSimple

// Funkcja do sprawdzania poprawności działania klasy SetSimple
void testSetSimple() {
    std::cout << "=== Testowanie podstawowych funkcjonalności SetSimple ===" << std::endl;
    
    // Test konstruktora i dodawania elementów
    SetSimple set1(10);
    set1.add(1);
    set1.add(3);
    set1.add(5);
    std::cout << "Set1: ";
    set1.display();
    assert(set1.contains(1) && set1.contains(3) && set1.contains(5));
    assert(!set1.contains(0) && !set1.contains(2) && !set1.contains(4));
    
    // Test metody remove
    set1.remove(3);
    std::cout << "Set1 po usunięciu 3: ";
    set1.display();
    assert(set1.contains(1) && !set1.contains(3) && set1.contains(5));
    
    // Test konstruktora kopiującego
    SetSimple set2 = set1;
    std::cout << "Set2 (kopia Set1): ";
    set2.display();
    assert(set2.contains(1) && !set2.contains(3) && set2.contains(5));
    
    // Test metody sum (sumy zbiorów)
    SetSimple set3(10);
    set3.add(2);
    set3.add(4);
    set3.add(5);
    std::cout << "Set3: ";
    set3.display();
    
    SetSimple set4 = set1.sum(set3);
    std::cout << "Set4 (suma Set1 i Set3): ";
    set4.display();
    assert(set4.contains(1) && set4.contains(2) && !set4.contains(3) && 
           set4.contains(4) && set4.contains(5));
    
    // Test metody intersection (części wspólnej)
    SetSimple set5 = set1.intersection(set3);
    std::cout << "Set5 (część wspólna Set1 i Set3): ";
    set5.display();
    assert(!set5.contains(1) && !set5.contains(2) && !set5.contains(3) && 
           !set5.contains(4) && set5.contains(5));
    
    // Test metody difference (różnicy zbiorów)
    SetSimple set6 = set1.difference(set3);
    std::cout << "Set6 (różnica Set1 - Set3): ";
    set6.display();
    assert(set6.contains(1) && !set6.contains(2) && !set6.contains(3) && 
           !set6.contains(4) && !set6.contains(5));
    
    // Test metody identical
    SetSimple set7(10);
    set7.add(1);
    set7.add(5);
    std::cout << "Set7: ";
    set7.display();
    
    bool identical1 = set1.identical(set7);
    bool identical2 = set1.identical(set3);
    std::cout << "Set1 identyczny z Set7: " << (identical1 ? "Tak" : "Nie") << std::endl;
    std::cout << "Set1 identyczny z Set3: " << (identical2 ? "Tak" : "Nie") << std::endl;
    assert(identical1);
    assert(!identical2);
    
    // Test metody clear
    set1.clear();
    std::cout << "Set1 po wyczyszczeniu: ";
    set1.display();
    assert(!set1.contains(1) && !set1.contains(5));
    
    // Test dodawania elementów poza zakresem
    SetSimple set8(5);
    set8.add(6);  // Ten element powinien zostać odrzucony
    std::cout << "Set8 z próbą dodania elementu poza zakresem (6): ";
    set8.display();
    assert(!set8.contains(6));
    
    std::cout << "Wszystkie testy podstawowych funkcjonalności przeszły pomyślnie!" << std::endl;
}

// Testowanie funkcji tworzących specjalne zbiory
void testSpecialSets() {
    std::cout << "\n=== Testowanie funkcji tworzących specjalne zbiory ===" << std::endl;
    
    // Test funkcji createConsecutiveSet
    SetSimple consecutive = createConsecutiveSet(3, 8);
    std::cout << "Kolejne liczby od 3 do 8: ";
    consecutive.display();
    assert(consecutive.contains(3) && consecutive.contains(4) && consecutive.contains(5) &&
           consecutive.contains(6) && consecutive.contains(7) && consecutive.contains(8));
    assert(!consecutive.contains(2) && !consecutive.contains(9));
    
    // Test funkcji createEvenStepSet
    SetSimple evenStep = createEvenStepSet(2, 10);
    std::cout << "Liczby od 2 do 10 z krokiem 2: ";
    evenStep.display();
    assert(evenStep.contains(2) && evenStep.contains(4) && evenStep.contains(6) &&
           evenStep.contains(8) && evenStep.contains(10));
    assert(!evenStep.contains(3) && !evenStep.contains(5) && !evenStep.contains(7) && 
           !evenStep.contains(9));
    
    // Test funkcji createAlphabetSet
    SetSimple alphabet = createAlphabetSet();
    std::cout << "Zbiór liter od a do z: ";
    alphabet.display_char();
    assert(alphabet.contains(0) && alphabet.contains(25));  // a i z
    
    // Test funkcji createTwoLetterSet
    SetSimple twoLetters = createTwoLetterSet();
    std::cout << "Przykładowe pary liter (pierwsze 10): ";
    // Wyświetlmy tylko kilka pierwszych par dla czytelności
    SetSimple firstFew(676);
    for(int i = 0; i < 10; i++) {
        firstFew.add(i);
    }
    firstFew.display_two_char();
    assert(twoLetters.contains(0) && twoLetters.contains(675));  // aa i zz
    
    std::cout << "Wszystkie testy funkcji specjalnych przeszły pomyślnie!" << std::endl;
}

// Test przypadków granicznych
void testEdgeCases() {
    std::cout << "\n=== Testowanie przypadków granicznych ===" << std::endl;
    
    // Test pustego zbioru
    SetSimple emptySet(5);
    std::cout << "Pusty zbiór: ";
    emptySet.display();
    
    // Test zbioru z jednym elementem
    SetSimple singleElement(5);
    singleElement.add(3);
    std::cout << "Zbiór z jednym elementem: ";
    singleElement.display();
    
    // Test zbioru z wszystkimi elementami
    SetSimple fullSet(5);
    for(int i = 0; i < 5; i++) {
        fullSet.add(i);
    }
    std::cout << "Pełny zbiór: ";
    fullSet.display();
    
    // Test operacji na pustych zbiorach
    SetSimple sumEmpty = emptySet.sum(emptySet);
    std::cout << "Suma dwóch pustych zbiorów: ";
    sumEmpty.display();
    assert(sumEmpty.identical(emptySet));
    
    SetSimple intersectionEmpty = emptySet.intersection(fullSet);
    std::cout << "Część wspólna pustego i pełnego zbioru: ";
    intersectionEmpty.display();
    assert(intersectionEmpty.identical(emptySet));
    
    // Test nieprawidłowych funkcji create
    SetSimple invalidConsecutive = createConsecutiveSet(8, 3); // n > m
    std::cout << "Nieprawidłowy zbiór kolejnych liczb (8 do 3): ";
    invalidConsecutive.display();
    
    SetSimple invalidEvenStep = createEvenStepSet(10, 2); // n > m
    std::cout << "Nieprawidłowy zbiór z krokiem 2 (10 do 2): ";
    invalidEvenStep.display();
    
    std::cout << "Wszystkie testy przypadków granicznych przeszły pomyślnie!" << std::endl;
}

int main() {
    testSetSimple();
    testSpecialSets();
    testEdgeCases();
    
    std::cout << "\nWszystkie testy zakończone pomyślnie!" << std::endl;
    return 0;
}