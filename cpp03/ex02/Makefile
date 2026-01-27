NAME=ex02

# /////////////////////////

CC=c++
CC_FLAGS=-Wall -Wextra -Werror -std=c++98

# /////////////////////////

DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
INCS= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS=$(SRCS:%.cpp=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:%.cpp=$(DIR_DEPS)/%.d)

# /////////////////////////

all: compile_start $(NAME) compile_done

compile_start:
	echo "$(GREEN)Compile start... $(END)"

compile_done:
	echo "$(GREEN)Compiling done $(END)"

$(NAME): $(OBJS) Makefile
	$(CC) $(CC_FLAGS) $(OBJS) -o $@
	echo "$(BLUE)Your ex02 is ready $(END)"

$(DIR_OBJS)/%.o: %.cpp Makefile 
	mkdir -p $(dir $@) $(DIR_DEPS)/$(dir $*)
	$(CC) $(CC_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

# /////////////////////////

clean:
	echo "$(RED)Removing files... $(END)"
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "$(RED)Removing executable... $(END)"
	rm -rf $(NAME)

re: fclean all

# /////////////////////////

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

# /////////////////////////

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
