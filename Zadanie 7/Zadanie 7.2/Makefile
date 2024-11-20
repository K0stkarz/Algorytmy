# Kompilator g++.

CXX = g++

# Flagi dla kompilatora C++.

CXXFLAGS = -Wall -std=c++11

# Pliki obiektowe - powstają z plików *.cpp.

OBJECTS = main.o

# Pliki nagłówkowe - są włączane do plików *.cpp.

HFILES = arraystack.h

# Końcowy plik wykonywalny.

TARGET = arraystack.out

# Definicja domyślnej reguły wzorcowej.

# $< oznacza nazwę pliku pierwszej zależności reguły.

# $@ oznacza nazwę pliku celu w regule.

# Wszystkie pliki obiektowe zależą od wszystkich plików nagłówkowych.

# Wcięcia robimy przez TAB.

%.o : %.cpp $(HFILES) Makefile

	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)

	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Określenie celów sztucznych.

.PHONY : clean

clean :

	$(RM) $(TARGET) *.o* core

