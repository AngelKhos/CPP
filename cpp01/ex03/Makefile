NAME=ex03
# /////////////////////////

CPP=c++
CPP_FLAGS=-Wall -Wextra -Werror -std=c++98

# /////////////////////////

DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INCS= HumanA.hpp HumanB.hpp Weapon.hpp
OBJS=$(SRCS:%.c=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:%.c=$(DIR_DEPS)/%.d)

# /////////////////////////

all: compile_start $(NAME) compile_done

compile_start:
	echo "$(GREEN)Compile start... $(END)"

compile_done:
	echo "$(GREEN)Compiling done $(END)"

$(NAME): $(OBJS) $(DEPS) Makefile
	$(CPP) $(CPP_FLAGS) $(OBJS) -o $@
	echo "$(BLUE)Your ex03 is ready $(END)"


$(DIR_OBJS)/%.o: %.c $(INCS) Makefile 
	mkdir -p $(dir $@) $(DIR_DEPS)/$(dir $*)
	$(CPP) $(CPP_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

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

.PHONY: all clean fclean re
.SILENT: