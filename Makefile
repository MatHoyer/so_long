CC = cc

CFLAGS = -I. -MMD -g3

SRC_PATH = sources/

OBJS_PATH = obj/

SRC = animation.c \
	annexe_parsing.c \
	check_input.c \
	do_case.c \
	error.c \
	init_player.c \
	init_texture.c \
	main.c \
	modif_matrix.c \
	movement.c \
	new_matrix.c \
	parsing.c \
	print_background.c \
	print_data.c \
	update_texture.c

OBJS = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

PREFC = $(addprefix $(SRC_PATH),$(SRC))

PREFO = $(addprefix $(OBJS_PATH),$(OBJS))

PREFD = $(addprefix $(OBJS_PATH),$(DEP))

NAME = so_long

all : $(NAME)

$(NAME) : $(PREFO)
	@make -s -C libft all 
	@make -s -C minilibx-linux all 
	@$(CC) $(PREFO) ./libft/libft.a ./minilibx-linux/libmlx.a -lX11 -lXext -o so_long
	@echo "Terminé!"

bonus : all

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(PREFO) $(PREFD)
	@make -s -C libft clean

fclean : clean
	@rm -f $(NAME)
	@make -s -C libft fclean
	@make -s -C minilibx-linux clean

re : fclean all

-include $(PREFD)

.PHONY : all clean fclean re
