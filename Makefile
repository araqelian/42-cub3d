NONE='\033[0m'
GREEN='\033[3;32m'
GRAY='\033[2;37m'
RED="\033[1;31m"
YELLOW="\033[1;33m"


NAME = cub3D

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

MKDIR = mkdir -p

OBJS_DIR = OBJS

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = $(wildcard *.c) $(wildcard src/*.c) $(wildcard utils/*.c)

_OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS = $(patsubst %.o, $(OBJS_DIR)/%.o, $(_OBJS))

$(OBJS_DIR)/%.o: %.c
	@ $(MKDIR) $(OBJS_DIR)/src
	@ $(MKDIR) $(OBJS_DIR)/utils
	@$(CC) $(FLAGS) $(INCLUDES) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(NONE)$(YELLOW) "- Compiling $(NAME)..." $(NONE)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(MLX)
	@echo $(NONE)$(GREEN)" - Compiled  $(NAME)\n"$(NONE)

clean:
	@echo $(RED) "- Removing  object files..." $(NONE)
	@ $(RM) $(OBJS_DIR)

fclean: clean
	@echo $(RED) "- Removing  $(NAME)..." $(NONE)
	@ $(RM) $(NAME)

re: fclean all

norm:
	clear
	norminette $(SRCS) cub3d.h

wc:
	clear
	wc -l $(SRCS)

.PHONY: all clean fclean re readline norm wc
