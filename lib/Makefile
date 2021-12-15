##
## EPITECH PROJECT, 2021
## LIBMY
## File description:
## make the libmy
##

TARGET		=	libmy.a

SRCGRAS		=	src/libgras/

OBJDIR		=	obj/

VPATH		=	$(SRCGRAS) $(SRCMY) $(OBJDIR) include/

SRC		=	$(wildcard $(SRCGRAS)*.c)

OBJ		:=	$(SRC:%.c=%.o)
OBJ		:=	$(addprefix $(OBJDIR), $(notdir $(OBJ)))

CFLAGS		=	-Iinclude -Wall -Wextra -Wpedantic

# ----------------------------------------------------------------------------

$(OBJDIR)%.o: %.c
	@$(CC)     $(CFLAGS)     $^ -c -o $@
	@echo -e '\033[0;36m$(notdir $^) -> $(notdir $@)\033[0m'

.PHONY: all
all:	$(TARGET) ## Call $(TARGET)

$(TARGET):	$(OBJ) ## Build the lib
	@ar rc $(TARGET) $(OBJ)
	@echo -e '\033[0;32mdone : $(TARGET)\033[0m'

.PHONY: clean
clean: ## Clean obj/*.o
	@rm -f $(OBJDIR)*.o

.PHONY: fclean
fclean:	clean ## Clean the binary
	@rm -f $(TARGET)

.PHONY: re
re:	fclean all ## Fclean+All
