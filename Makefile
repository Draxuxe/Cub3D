# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 18:06:47 by lfilloux          #+#    #+#              #
#    Updated: 2022/11/02 14:37:40 by lfilloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

# Program name
NAME = cub3D
NAME_BONUS = cub3D_bonus

INC_DIR = includes/
INC_DIR_BNS = includes_bonus/
SRC_DIR = srcs/
BONUS_DIR = ./srcs_bonus/
OBJ_DIR = objs/
BONUS_OBJ_DIR = bonus_objs/

# Includes
_INCS =	cub3d.h	\
		structures.h

_INCS_BNS =	cub3d_bonus.h	\
			structures_bonus.h

# Sources
_SRCS =	main.c							\
		Init/init_map.c					\
		Init/init_perso.c				\
		Parsing/parse.c					\
		Parsing/read_map.c				\
		Parsing/parse_texture.c			\
		Parsing/parse_color.c			\
		Parsing/parse_map.c				\
		Parsing/check_name_map.c		\
		Parsing/check_params.c			\
		Parsing/check_border.c			\
		Utils/array.c					\
		Utils/find.c					\
		Utils/get_next_line.c			\
		Utils/exit.c					\
		Raycaster/move.c				\
		Raycaster/key_press.c			\
		Raycaster/texture.c				\
		Raycaster/raycasting.c			\
		Raycaster/load.c

_BNS =	main.c							\
		Init/init_map.c					\
		Init/init_struct.c				\
		Parsing/parse.c					\
		Parsing/read_map.c				\
		Parsing/parse_texture.c			\
		Parsing/parse_color.c			\
		Parsing/parse_map.c				\
		Parsing/check_name_map.c		\
		Parsing/check_params.c			\
		Parsing/check_border.c			\
		Utils/array.c					\
		Utils/find.c					\
		Utils/get_next_line.c			\
		Raycaster/exit.c				\
		Raycaster/mouse.c				\
		Raycaster/kart.c				\
		Raycaster/piece.c				\
		Raycaster/move.c				\
		Raycaster/minimap.c				\
		Raycaster/raycasting.c			\
		Raycaster/calc_sprite.c			\
		Raycaster/predraw.c				\
		Raycaster/sprite.c				\
		Raycaster/key_push.c			\
		Raycaster/open_window.c

SRCS = $(addprefix $(SRC_DIR), $(_SRCS))
SRCS_BNS = $(addprefix $(BONUS_DIR), $(_BNS))
OBJS = $(addprefix $(OBJ_DIR), $(_SRCS:.c=.o))
OBJS_BNS = $(addprefix $(BONUS_OBJ_DIR), $(_BNS:.c=.o))
INCS = $(addprefix $(INC_DIR), $(_INCS))
INCS_BNS = $(addprefix $(INC_DIR_BNS), $(_INCS_BNS))

MLX = mlx/
MLX_LINK = mlx/libmlx.a
LINKS = mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT = Libft/
LIBFT_LINK = $(LIBFT)libft.a

# Compile
CC = gcc

# Flags
CFLAGS = -Wall -Werror -Wextra -O3 -Ofast -ffast-math
INCLUDE = -I $(INC_DIR)
INCLUDE_BNS = -I $(INC_DIR)

# Rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/Init
	@mkdir -p $(OBJ_DIR)/Parsing
	@mkdir -p $(OBJ_DIR)/Utils
	@mkdir -p $(OBJ_DIR)/Raycaster
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(INCS) $(OBJS)
	@echo "Number of objs files: [$(words $(OBJS))]"
	@make -s -C $(MLX) all
	@echo "[MINILIBX] $(FG_GREE)Minilibx compiled.$(FG_WHIT)"
	@make -s -C $(LIBFT) all
	@echo "[LIBFT] $(FG_GREE)Libft compiled.$(FG_WHIT)"
	@$(CC) $(CFLAGS) $(LIBFT_LINK) $(MLX_LINK) $(LINKS) $(OBJS) -o $(NAME)
	@echo "[CUB3D] $(FG_GREE)Ready to launch '$(NAME)'.$(FG_WHIT)"

all: $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(NAME)
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT) clean
	@make -s -C $(MLX) clean
	@echo "[CUB3D]"
	@echo "$(FG_MAGE)Objects files cleaned.$(FG_WHIT)"

fclean: clean
	@rm -f $(NAME) $(OBJS)
	@echo "[CUB3D]"
	@echo "$(FG_MAGE)Program files cleaned.$(FG_WHIT)"
	@make -s -C $(LIBFT) fclean
	@make -s -C $(MLX) clean
	@echo "$(FG_MAGE)Objects cleaned.$(FG_WHIT)"

re: fclean all

# Bonus
$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@mkdir -p $(BONUS_OBJ_DIR)/Init
	@mkdir -p $(BONUS_OBJ_DIR)/Parsing
	@mkdir -p $(BONUS_OBJ_DIR)/Utils
	@mkdir -p $(BONUS_OBJ_DIR)/Raycaster
	@$(CC) $(CFLAGS) $(INCLUDE_BNS) -c $< -o $@

$(NAME_BONUS): $(INCS_BNS) $(OBJS_BNS)
	@echo "Number of objs files: [$(words $(OBJS_BNS))]"
	@make -s -C $(MLX) all
	@echo "[MINILIBX] $(FG_GREE)Minilibx compiled.$(FG_WHIT)"
	@make -s -C $(LIBFT) all
	@echo "[LIBFT] $(FG_GREE)Libft compiled.$(FG_WHIT)"
	@$(CC) $(CFLAGS)  $(LIBFT_LINK) $(MLX_LINK) $(LINKS) $(OBJS_BNS) -o $(NAME_BONUS)
	@echo "[CUB3D_BONUS] $(FG_GREE)Ready to launch '$(NAME_BONUS)'.$(FG_WHIT)"


clean_bonus:
	@rm -f $(OBJS_BNS) $(NAME_BONUS)
	@rm -rf $(BONUS_OBJ_DIR)
	@make -s -C $(LIBFT) clean
	@make -s -C $(MLX) clean
	@echo "[CUB3D_BONUS]"
	@echo "$(FG_MAGE)Objects files cleaned.$(FG_WHIT)"

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS) $(OBJS_BNS)
	@echo "[CUB3D_BONUS]"
	@echo "$(FG_MAGE)Program files cleaned.$(FG_WHIT)"
	@make -s -C $(LIBFT) fclean
	@make -s -C $(MLX) clean
	@echo "$(FG_MAGE)Objects cleaned.$(FG_WHIT)"

re_bonus: fclean_bonus $(NAME_BONUS)

.PHONY: all clean fclean re clean_bonus fclean_bonus re_bonus