##
## EPITECH PROJECT, 2021
## sample
## File description:
## sample description
##

TARGET		=	my_runner

LIB_TARGET	=	lib/libmy.a

TARGET_TEST	=	bin_test

SRCDIR		=	src/

VPATH		=	$(SRCDIR) lib/ include/ tests/

SRC		:=	$(shell find $(SRCDIR) -name '*.c')
SRC		:=	$(filter-out $(SRCDIR)main.c, $(SRC))

OBJ		:=	$(SRC:%.c=%.o)

MAIN_SRC	=	$(SRCDIR)main.c

MAIN_OBJ	:=	$(MAIN_SRC:%.c=%.o)

TEST_SRC	= 	$(wildcard tests/*.c)

TEST_OBJ	:=	$(TEST_SRC:%.c=%.o)

CFLAGS		= 	-Iinclude/ -Ilib/include/ -Wall -Wextra -Wpedantic

LFLAGS		=	-Llib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-audio -lcsfml-window

CR_TEST_FLAGS	=	-lcriterion

FN_TEST_FLAGS	=	-ftest-coverage -fprofile-arcs

# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC)     $(CFLAGS)    $^ -c -o $@
	@echo -e '\033[0;36m$(notdir $^) -> $(notdir $@)\033[0m'

.PHONY: all
all:	$(LIB_TARGET) $(TARGET) ## Build lib+binary

$(TARGET):	$(OBJ) $(MAIN_OBJ) ## Build the binary
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS) $(CFLAGS)
	@echo -e '\033[0;32mdone : $(TARGET)\033[0m'

$(LIB_TARGET): ## Build the lib
	$(MAKE) -C lib/

.PHONY: clean
clean: ## Clean obj and gcno/gcda
	@rm -f $(OBJ) $(MAIN_OBJ)
	@rm -f vgcore.*
	@rm -f `find . -name '*.gcno'`
	@rm -f `find . -name '*.gcda'`

.PHONY: fclean
fclean:	clean ## Clean+Remove target/target_test and call lib fclean
	@$(MAKE) -C lib/ fclean -s
	@rm -f $(TARGET) $(TARGET_TEST)
	@echo -e '\033[0;32mdone : fclean\033[0m'

.PHONY: re
re:	fclean all ## Fclean+All

.PHONY: debug
debug: CFLAGS += -g3
debug: re
	valgrind --leak-check=full --suppressions=valgrind.supp \
		./$(TARGET) map/42.txt

.PHONY: tests_run
tests_run: all ## The rule called by Marvin to make coverage

.PHONY: make_prog
make_prog: re
	rm -rf ../geometry-glitch/
	rm -rf ../geometry-glitch.tar.gz
	mkdir ../geometry-glitch/
	cp $(TARGET) ../geometry-glitch/
	cp -r assets/ ../geometry-glitch
	cp -r map/ ../geometry-glitch
	tar czf ../geometry-glitch.tar.gz ../geometry-glitch/
	rm -rf ../geometry-glitch/
