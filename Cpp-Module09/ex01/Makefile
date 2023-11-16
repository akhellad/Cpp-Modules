# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:10:19 by akhellad          #+#    #+#              #
#    Updated: 2023/11/09 11:10:21 by akhellad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
SRCDIR = srcs
OBJDIR = obj
SRCS = $(SRCDIR)/RPN.cpp $(SRCDIR)/main.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
INCLUDES = -I includes
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
