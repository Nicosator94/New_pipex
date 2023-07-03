CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g3 -I.

SOURCES = main.c \
	init_struct.c \
	init_cmd.c \
	check_path.c \
	path_already_given.c \
	set_env.c \
	pipex.c \
	multi_pipex.c \
	wait_all.c \
	error.c

SRC = srcs/
DIR = objs_deps/

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

SRCS_BNS = main_bonus.c \
	init_struct_bonus.c \
	init_cmd_bonus.c \
	check_path_bonus.c \
	path_already_given_bonus.c \
	set_env_bonus.c \
	pipex_bonus.c \
	multi_pipex_bonus.c \
	wait_all_bonus.c \
	error_bonus.c

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	@make -sC libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation"
	@echo "Wait ..."
	@mkdir -p objs_deps

clean :
	@echo "Deleting Objects and Dependencies"
	@make fclean -sC libft
	@rm -rf $(DIR)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all bonus clean fclean re