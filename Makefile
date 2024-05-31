YELLOW="\033[0;33m"
RED="\033[1;31m"
GREEN='\033[3;32m'
NONE='\033[0m'

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) $(wildcard src/*.c) $(wildcard utils/*.c)

MLX = ./mlxLib

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -rf

FMS = -lmlx -framework OpenGL -framework AppKit 

MD = mkdir -p

ifeq ($(shell uname -s), Linux)
	MLX = minilibx-linux
	FMS = -lmlx -lm -lX11 -lXext
endif

all: mlx  $(NAME)

%.o : %.c
	@$(CC) -s $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) -s $(OBJS) $(CFLAGS) -L$(MLX) $(FMS) -o $(NAME)
	@echo $(NONE) $(GREEN)"       Compiled $(NAME) " $(NONE)

mlx:
	@make -s -C $(MLX) >/dev/null 2>&1

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
