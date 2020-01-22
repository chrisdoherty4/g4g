CXX = g++

all: 
	$(CXX) brute-force.cc -o brute-force

clean:
	rm -rf *.o brute-force

test:
	cat ../meta/test-1.txt | ./brute-force
