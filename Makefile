CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g3 -I.

SRCS = main.c \
	init_struct.c \
	init_cmd.c \
	check_path.c \
	set_env.c \
	pipex.c \
	wait_all.c

SRC = srcs/
DIR = objs_deps/

OBJS = $(addprefix $(SRC), $(SRCS))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

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