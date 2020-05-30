CC = clang

NAME = lem-in

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
DFLAGS += -fsanitize=address,undefined -g3

INCLUDES = includes/
HEAD += lem-in.h

PATHSRCS = srcs/
SRCS += main.c

PATHO = objs/
OBJS = $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS))

PATHLIB = libft/
LIBINCLUDES = $(PATHLIB)includes
LIBFT = $(PATHLIB)libft.a

vpath %.c $(PATHSRCS)
vpath %.h $(INCLUDES)

all: $(NAME)

$(NAME): $(LIBFT) $(PATHOBJS) $(OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(PATHLIB)

$(OBJS): $(PATHOBJS)%.o: %.c $(HEAD) Makefile
	$(CC) -c $(CFLAGS) $(DFLAGS) $< -I $(INCLUDES) -I $(LIBINCLUDES) -o $@ 

$(PATHOBJS):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATHOBJS)
	$(MAKE) clean -C $(PATHLIB)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PATHLIB)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
