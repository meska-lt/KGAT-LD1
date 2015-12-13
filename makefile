COMPILER=g++
EXECUTABLE=initials
EXTENSION_APP_RESULT=.bmp
EXTENSION_OBJECT=.o

all: $(EXECUTABLE)

$(EXECUTABLE): main.o BMP24.o
	$(COMPILER) main.o BMP24.o -o initials

main.o: main.cpp
	$(COMPILER) -c main.cpp

BMP24.o: BMP24.cpp
	$(COMPILER) -c BMP24.cpp

clean:
	rm *$(EXTENSION_OBJECT) *$(EXTENSION_APP_RESULT) $(EXECUTABLE)