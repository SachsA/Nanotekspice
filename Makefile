##
## EPITECH PROJECT, 2018
## Nano
## File description:
## Makefile
##

NAME		= plop

TRUE_NAME	= nanotekspice

TEST_NAME	= nanotester

RM		= rm -rf

CC		= g++

SRC		= Special/Clock.cpp			\
		  Special/Input.cpp			\
		  Special/Output.cpp			\
		  Shell/Shell.cpp			\
		  Gates/And.cpp				\
		  Gates/Nand.cpp			\
		  Gates/Nor.cpp				\
		  Gates/Or.cpp				\
		  Gates/Xor.cpp				\
		  Gates/Inverter.cpp			\
		  Components/Adder.cpp			\
		  Components/DualFlipFlop.cpp		\
		  Components/SixInverterGates.cpp	\
		  SubComponents/Ram.cpp			\
		  SubComponents/Sum.cpp			\
		  SubComponents/FlipFlop.cpp		\
		  Parser/Parser.cpp			\
		  Errors/Errors.cpp			\
		  Errors/ErrorsPin.cpp			\
		  Errors/ErrorsFile.cpp			\
		  Errors/ErrorsLink.cpp			\
		  Errors/ErrorsInput.cpp		\
		  Errors/ErrorsShell.cpp		\
		  Errors/ErrorsChipset.cpp		\
		  Circuit.cpp				\
		  Factory.cpp

TEST_SRC	= Tests/MainTester.cpp			\
		  Tests/Gates.cpp

OBJ		= $(SRC:.cpp=.o)

# Only for clean object files
TEST_OBJ	= $(TEST_SRC:.cpp=.o)

CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -I ./ -I Components -I Gates -I SubComponents -I Special -I Errors/Include -I Parser -I Shell

ifeq ($(DEBUG), TRUE)
	CXXFLAGS += -g
else
	CXXFLAGS += -Werror
endif

ifeq ($(BONUS), TRUE)
	CXXFLAGS += -D__BONUS__
endif

ifeq ($(TEST), TRUE)
	CXXFLAGS += -I Tests
	SRC += $(TEST_SRC)
	NAME = $(TEST_NAME)
else
	SRC += Main.cpp
	NAME = $(TRUE_NAME)
endif

$(NAME): $(OBJ)
	$(RM) $(TRUE_NAME)
	$(RM) $(TEST_NAME)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) Main.o
	$(RM) $(OBJ)
	$(RM) $(TEST_OBJ)

fclean: clean
	$(RM) $(TRUE_NAME)
	$(RM) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re
