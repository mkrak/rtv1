NAME		=	rt
SHEL		=	/bin/bash

OS			=	$(shell uname -s)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	libft/
MLX_DIR		=	minilibx_macos/
SRCS_DIR	=	srcs/
SRCS_LIST	=	 aliasing.c \
autres.c \
check_token.c \
damier.c \
export.c \
export_2.c \
export_3.c \
filtre.c \
get_token.c \
handle_obj.c \
handle_scene.c \
handle_token.c \
init.c \
key_pr.c \
key_pr_2.c \
keyhook.c \
loadbar.c \
main.c \
main_func.c \
main_mouse_hook_0.c \
menu.c \
menu_2.c \
menu_hook_1.c \
menu_hook_2.c \
menu_hook_3.c \
mlx.c \
mlx_2.c \
multithread.c \
ope_vec.c \
ope_vec2.c \
quadric.c \
rotation.c \
rt.c \
intersec.c \
set_attr.c \
set_attr_funcs.c \
surface.c \
trace_info_0.c \
trace_info_1.c \
trace_info_2.c \
trace_info_3.c \
utils.c \
utils_2.c \
autres_2.c \
check_ressources.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR	=	objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))
    HEADERS		=	-I./libft -I./includes
ifeq ($(OS),Linux)
    LIBS		=	-lmlx -lXext -lX11 -lbsd -L./libft -lft -lm -lpthread
else
    LIBS		=	-framework OpenGl -framework AppKit -lmlx -L./libft -L./minilibx_macos libft/libft.a minilibx_macos/libmlx.a
endif


.PHONY : all clean

all : $(NAME)

$(NAME) : $(OBJS)
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(MLX_DIR)
	@echo "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

norme :
	@norminette $(SRCS)

clean :
	@make clean --no-print-directory -C $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean : clean
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@rm -rf $(NAME)	
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all
