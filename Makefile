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

SOURCES_BONUS = main_bonus.c \
	init_struct_bonus.c \
	init_cmd_bonus.c \
	check_path_bonus.c \
	path_already_given_bonus.c \
	set_env_bonus.c \
	pipex_bonus.c \
	multi_pipex_bonus.c \
	wait_all_bonus.c \
	error_bonus.c

SRC = srcs/
DIR = objs_deps/

SRC_BONUS = srcs_bonus/
DIR_BONUS = objs_deps_bonus/

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))

SRCS_BONUS = $(addprefix $(SRC_BONUS), $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(DIR_BONUS), $(OBJ_BONUS))
DEPS_BONUS = $(addprefix $(DIR_BONUS), $(DEP_BONUS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)
DEP_BONUS = $(SOURCES_BONUS:.c=.d)

NAME = pipex

NAME_BONUS = pipex_bonus

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make -sC libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	@echo "Compilation completed"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make -sC libft
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) ./libft/libft.a
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(DIR_BONUS)%.o : $(SRC_BONUS)%.c | $(DIR_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation"
	@echo "Wait ..."
	@mkdir -p objs_deps

$(DIR_BONUS) :
	@echo "Start Compilation"
	@echo "Wait ..."
	@mkdir -p objs_deps_bonus

clean :
	@echo "Deleting Objects and Dependencies"
	@make fclean -sC libft
	@rm -rf $(DIR)
	@rm -rf $(DIR_BONUS)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY : all bonus clean fclean re