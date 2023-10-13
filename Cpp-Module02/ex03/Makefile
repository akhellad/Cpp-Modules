CXX = g++
CXXFLAGS = -Wall -Werror -Wextra

all: a.out

a.out: srcs/main.o srcs/Fixed.o srcs/Point.o srcs/bsp.o
	$(CXX) $(CXXFLAGS) -o a.out srcs/main.o srcs/Fixed.o srcs/Point.o srcs/bsp.o

srcs/main.o: srcs/main.cpp
	$(CXX) $(CXXFLAGS) -c -o srcs/main.o srcs/main.cpp

srcs/Fixed.o: srcs/Fixed.cpp
	$(CXX) $(CXXFLAGS) -c -o srcs/Fixed.o srcs/Fixed.cpp

srcs/Point.o: srcs/Point.cpp
	$(CXX) $(CXXFLAGS) -c -o srcs/Point.o srcs/Point.cpp

srcs/bsp.o: srcs/bsp.cpp
	$(CXX) $(CXXFLAGS) -c -o srcs/bsp.o srcs/bsp.cpp

clean:
	rm -f a.out srcs/*.o