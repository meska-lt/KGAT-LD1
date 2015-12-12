COMPILER=g++
EXECUTABLE=initials

all: $(EXECUTABLE)

$(EXECUTABLE): main.o BMP24.o
	$(COMPILER) main.o BMP24.o -o initials

main.o: main.cpp
	$(COMPILER) -c main.cpp

BMP24.o: BMP24.cpp
	$(COMPILER) -c BMP24.cpp

clean:
	rm *.o *.bmp initials