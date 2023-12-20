# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2023/12/19 12:45:47 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fractol
CC          := cc
CFLAGS       := -Wall -Wextra -Werror
RM		    := rm -f
INCLUDE = -Ift_printf/ -Ilibft/ -Iminilibx/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
MINILIBX_DIR = minilibx/
MINILIBX = minilibx/libmlx.a
PRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

SRCS        := 				julia.c \
							mandle.c \
							math.c \
							mlx_util.c \
							movement_util.c \
							movement.c \
							parsing.c \
							parsing_2.c \


SRCSM1       :=            fractol.c \


                          
OBJS        := $(SRCS:.c=.o)
OBJSNAME    := $(SRCSM1:.c=.o)

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) $(LIBFT) $(PRINTF)
MINI = -L$(MINILIBX_DIR) $(MINILIBX)

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@
	
    
${NAME}:	${OBJS} ${OBJSNAME} $(LIBFT) $(PRINTF) $(MINILIBX)
			@${CC} ${CFLAGS} $(INCLUDES) ${OBJS} ${OBJSNAME} $(LIBS) $(MINI) -framework OpenGL -framework AppKit -lm -o ${NAME} 
			@echo "\033[0;32mFractol compiled successfully"
$(LIBFT):
	        @make -C $(LIBFT_DIR) -s
			@echo "\033[0;32mLibft compiled successfully"


$(PRINTF):
			@make -C $(PRINTF_DIR) -s
			@echo "\033[0;32mPrintf compiled successfully"

			
$(MINILIBX):
	        @make -C $(MINILIBX_DIR) -s
			@echo "\033[0;32mMinilibx compiled successfully"

all:		${NAME}

clean:
			@${RM} *.o
			@make -C $(LIBFT_DIR) clean -s
			@make -C $(PRINTF_DIR) clean -s
			@make -C $(MINILIBX_DIR) clean -s
			@echo "\033[0;31mObjects removed successfully"


fclean:		clean
			@${RM} ${NAME}
			@make -C $(LIBFT_DIR) fclean -s
			@make -C $(PRINTF_DIR) fclean -s
			@make -C $(MINILIBX_DIR) clean -s
			@echo "\033[0;31mAll created objects were removed successfully"

re:			fclean all
			@echo "\033[0;32mFractol was recompiled successfully"

.PHONY:		all clean fclean re bonus