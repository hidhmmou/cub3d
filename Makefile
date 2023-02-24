NAME		=	cub3d
CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc
OBJ			=	$(SRC:.c=.o)
LIBFT		=	libft/libft.a
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
RESET		=	\033[0m
PARSING		=	check_map.c get_next_line.c utils_00.c utils_01.c
EXEC		=	
SRC 		=	cub3d.c $(EXEC_SRC) $(PARSE_SRC)
EXEC_SRC	=	$(addprefix executing/, $(EXEC))
PARSE_SRC	=	$(addprefix parsing/, $(PARSING))


all			:	$(NAME)
	
$(NAME)		:	$(LIBFT) $(OBJ)
				@$(CC) $(OBJ) -o $(NAME) $(LIBFT)
				@echo "$(BLUE)cub3d$(GREEN)\r\t\t\t compiled$(RESET)"
				@make clean

$(LIBFT)	:
				@make -C ./libft
				@echo "$(GREEN)libft:\r\t\t\t compiled$(RESET)"

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(BLUE)$<:$(RESET)\r\t\t\t $(GREEN)compiled$(RESET)"

clean		:
				@rm -f $(OBJ) $(BONUS_OBJ)
				@echo "$(YELLOW)object files cleaned$(RESET)"

fclean		:	clean
				@rm -f $(NAME) $(BONUS)
				@echo "$(RED)cub3d cleaned$(RESET)"

re			:	fclean all

.PHONY		:	clean all fclean re