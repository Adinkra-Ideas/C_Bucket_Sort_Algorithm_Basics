NAME = sorter
TNAME = tester

SRCS =	main.c	\
		main_utils.c	\
		main_utils_2.c	\
		main_utils_3.c	\
		main_utils_4.c	\
		main_utils_5.c	\
		commands.c	\
		algo.c	\

TSRC = test/srcs/main.c	test/srcs/commands.c	test/srcs/main_utils.c	\
	srcs/main_utils.c	srcs/main_utils_2.c \
	srcs/main_utils_3.c	srcs/main_utils_4.c	srcs/main_utils_5.c	\
	srcs/commands.c	srcs/algo.c

OBJDIR = build/
SRCDIR = srcs/
HEADER = includes/

OBJS := $(SRCS:.c=.o)
SRCS_PREFIXED := $(addprefix $(SRCDIR), $(SRCS))
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

TOBJ = $(subst .c,.o,$(TSRC))

CC = cc

CFLAGS = -Wall	-Werror	-Wextra -pedantic -g3 -fsanitize=address -D BUFFER_SIZE=1200

all: $(NAME)

$(NAME): $(OBJECTS_PREFIXED) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) -o $(NAME)

$(OBJECTS_PREFIXED): $(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -I$(HEADER) $< -o $@ 

checker: $(TNAME)

$(TNAME): $(TOBJ)
	$(CC) $(CFLAGS) -o $(TNAME)	$(TOBJ)


clean:
	/bin/rm -rf $(OBJDIR) $(TOBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(TNAME)

re: fclean all

.PHONY:	all	clean	fclean	re
