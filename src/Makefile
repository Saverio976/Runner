##
## EPITECH PROJECT, 2021
## sample
## File description:
## sample description
##

OBJDIR		:=	obj/

SRCDIRGAME	:=	game/

SRCDIRINTRO	:=	intro/

SRCDIRMENU	:=	menu/

SRCDIRSETT	:=	settings/

SRCGAME		:=	$(wildcard $(SRCDIRGAME)*.c)

SRCINTRO	:=	$(wildcard $(SRCDIRINTRO)*.c)

SRCMENU		:=	$(wildcard $(SRCDIRMENU)*.c)

SRCSETT		:=	$(wildcard $(SRCDIRSETT)*.c)

SRC		:=	$(SRCGAME) $(SRCINTRO) $(SRCMENU) $(SRCSETT)

VPATH		=	$(SRCDIR) $(OBJDIR)

OBJ		:=	$(SRC:%.c=%.o)
OBJ		:=	$(addprefix $(OBJDIR), $(OBJ))

WFLAGS		:=	-g3 -Wall -Wextra -Wpedantic

CFLAGS		+= 	-I../include/ -I../lib/include/ $(WFLAGS)

# ----------------------------------------------------------------------------

$(OBJDIR)%.o: %.c
	$(CC)    $(CFLAGS)    $^ -c -o $(OBJDIR)$(notdir $@)

.PHONY: all
all: $(OBJ)

.PHONY: clean
clean: ## Clean obj and gcno/gcda
	rm -f $(OBJDIR)*.o
	rm -f vgcore.*
	rm -f **/*.gcno **/*.gcda

.PHONY: re
re:	fclean all ## Fclean+All
