.PHONY: all clean

CFLAGS = --std=c++0x -I./include -g

all: obj/write

obj/write: obj/write_message.o
	$(CXX) $^ -o $@ 

obj/%.o: src/%.cpp
	$(CXX) -c $^ -o $@ $(CFLAGS)

clean:
	@rm -rf src/*~ obj/* *~ core data.mspk

test: obj/write
	@obj/write data.mspk
	@src/read_message.py data.mspk

