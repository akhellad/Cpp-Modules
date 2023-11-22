CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
TARGET = BSP
SRC = srcs/main.cpp srcs/Fixed.cpp srcs/Point.cpp srcs/bsp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re