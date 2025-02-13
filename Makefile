

CC=g++
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# Generate source and object lists, also just string variables
C_SRCS := \
	$(wildcard *.cpp)

HDRS := \
	$(wildcard *.h)
OBJS := Header.o Pixel.o Image.o manip.o mainDriver.o 

C_SRCS := \
	$(wildcard *.cpp) \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp)

HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))
# default target
all: build
		@echo "All Done!"

# Link all built objects
build: $(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# special build rule
%.o: %.c $(HDRS)
		$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(HDRS)
		$(CC) $(CFLAGS) -c $< -o $@

which:
		@echo "FOUND SOURCES: ${C_SRCS}"
		@echo "FOUND HEADERS: ${HDRS}"



#Catch root directory src files

bin/%.o: %.cpp $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

#Catch all nested directory files
bin/%.o: src/%.cpp $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@


clean:
		rm -f $(TARGET)
		rm -rf bin 


run: build
		./$(TARGET) ClemsonPaw.ppm Disney.ppm
