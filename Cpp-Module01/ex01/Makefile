# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 23:32:28 by akhellad          #+#    #+#              #
#    Updated: 2023/09/01 00:23:22 by akhellad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = Brainz


SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

CC = c++
CFLAGS = -Wall -Wextra -std=c++98 -g

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

INCLUDES = $(wildcard $(INCDIR)/*.h)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -rf $(OBJECTS) $(TARGET) $(OBJDIR)

all: $(TARGET)


.DEFAULT_GOAL := all

.PHONY: clean all