CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=fibonacci.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=output

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) *~
