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

SRC	=	$(D_SRC)main.c				\
		$(D_SRC)check.c				\
		$(D_SRC)draw.c				\
		$(D_SRC)init.c				\
		$(D_SRC)line.c				\
		$(D_SRC)update.c			\
		$(D_SRC)window.c			\
		$(D_SRC)iso.c				\
		$(D_SRC)triangle.c			\
		$(D_SRC)z_buff.c			\
		$(D_SRC)display.c			\
		$(D_SRC)transform.c			\
		$(D_SRC)file_obj.c			\
		$(D_SRC)init_obj.c			\
		$(D_SRC)set_obj.c			\
		$(D_SRC)my_getfloat.c			\
		$(D_SRC)init_img.c			\
		$(D_SRC)draw_poly.c			\
		$(D_SRC)draw_poly_interpolation.c	\
		$(D_SRC)draw_poly_init.c		\
		$(D_SRC)init_button.c			\
		$(D_SRC)make_button.c			\
		$(D_SRC)action_on_obj.c			\
		$(D_SRC)save_file.c			\
		$(D_SRC)init_text.c			\
		$(D_SRC)get_text.c			\
		$(D_SRC)save_write.c			\
		$(D_SRC)set_triangle.c			\
		$(D_SRC)load_file.c			\

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME	=	my_world

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -l csfml-graphics -l csfml-system  -l csfml-window -lm

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
