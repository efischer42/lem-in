CC = clang

NAME = lem-in

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
DFLAGS += -fsanitize=address,undefined -g3

INCLUDES = includes/
HEAD += lem-in.h
HEAD += lem-in_enum.h
HEAD += lem-in_struct.h

PATHSRCS = srcs/
SRCS += del.c
SRCS += error.c
SRCS += get_a_path.c
SRCS += get_ants_nb.c
SRCS += get_rooms.c
SRCS += get_paths.c
SRCS += get_pipes.c
SRCS += get_word.c
SRCS += lexer.c
SRCS += lexer_parser.c
SRCS += main.c
SRCS += parser.c
SRCS += send_ants.c
SRCS += solve.c
SRCS += utils.c

PATHDEBUG = debug/
SRCS += debug.c
SRCS += debug_ants.c
SRCS += debug_paths.c
SRCS += debug_rooms.c

PATHOBJS = objs/
OBJS = $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS))

PATHLIB = libft/
LIBINCLUDES = $(PATHLIB)includes
LIBFT = $(PATHLIB)libft.a

vpath %.c $(PATHSRCS)
vpath %.c $(PATHDEBUG)
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
