.PHONY	:= all clean
#CC		:= g++
CC		:= clang++
# CFLAGS 	:= -O2
# CFLAGS 	:= -O3
# CFLAGS 	:= -Ofast
CFLAGS	:= -g -Wall -Wextra -pedantic
SRC		:= $(wildcard ./*.cpp)
OBJ		:= $(SRC:%.cpp=%.o)
YKES	:= ./

all: ykes

ykes:	$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lrt

%.o:	$(YKES)%.cpp
	$(CC) -I$(YKES)includes -c $< $(CFLAGS)

clean:
	rm -rf *.dSYM *.o *.d ykes*
