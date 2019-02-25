##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	= 	cc

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c			\
		$(D_SRC)check.c			\
		$(D_SRC)draw.c			\
		$(D_SRC)init.c			\
		$(D_SRC)line.c			\
		$(D_SRC)update.c		\
		$(D_SRC)window.c		\
		$(D_SRC)iso.c			\
		$(D_SRC)display_2d_map.c	\
		$(D_SRC)make_map.c		\
		$(D_SRC)triangle.c		\
		$(D_SRC)z_buff.c		\

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME	=	my_world

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -l csfml-graphics -l csfml-system -lm

BUILD_DIR = build

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(D_LIB) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME) *~

libmy:
	@make -C $(D_LIB) --no-print-directory

$(NAME): libmy options $(OBJ)
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
