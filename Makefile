#===============================================================================: Filename
NAME		= philosophers

#===============================================================================: Source to object conversion location
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#===============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#===============================================================================: Compile variables
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKEFLAGS	= --no-print-directory
RM			= rm -rf
MKDIR		= mkdir -p
HEADERS		= -I include

#===============================================================================: Sourcefiles
SRCS		= 	$(addprefix src/, $(addsuffix .c, \
					main \
				$(addprefix utils/, \
					validate_input \
					init_data \
					time \
					check_sim \
					print) \
				$(addprefix functions/, \
					ft_atoi \
					ft_bzero \
					ft_calloc \
					ft_isdigit \
					ft_isspace \
					ft_memset) \
				$(addprefix simulation/, \
					execute \
					threads \
					philo_actions)))

#===============================================================================: Make commands
all: message $(NAME)
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME) -lpthread
	@printf "$(GREEN)✅Executable \"$(NAME)\" created!$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR) objs
	@$(MKDIR) objs/utils
	@$(MKDIR) objs/functions
	@$(MKDIR) objs/testing
	@$(MKDIR) objs/simulation
	@$(CC) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
run: all
	@printf "$(GREEN)Executing $(NAME)!\n$(RESET)\n"
	@./$(NAME) $(RUN_ARGS)

#===============================================================================: Build messages
message:
	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

#===============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files and executable
fclean:
	@$(RM) objs/
	@$(RM) $(NAME)
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run