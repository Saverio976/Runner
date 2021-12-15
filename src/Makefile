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

WFLAGS		:=	-Wall -Wextra -Wpedantic

CFLAGS		+= 	-I../include/ -I../lib/include/ $(WFLAGS)

# ----------------------------------------------------------------------------

$(OBJDIR)%.o: %.c
	@$(CC)    $(CFLAGS)    $^ -c -o $(OBJDIR)$(notdir $@)
	@echo -e '\033[0;36m$(notdir $^) -> $(notdir $@)\033[0m'

.PHONY: all
all: $(OBJ)
	@echo -e '\033[0;32mdone : scenes\033[0m'

.PHONY: clean
clean: ## Clean obj and gcno/gcda
	@rm -f $(OBJDIR)*.o
	@rm -f vgcore.*
	@rm -f **/*.gcno **/*.gcda

.PHONY: re
re:	clean all ## Fclean+All
