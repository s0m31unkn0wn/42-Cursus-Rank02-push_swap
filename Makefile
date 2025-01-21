NAME = push_swap

LIBFT = ./libft
LIBFT_A = $(LIBFT)/libft.a

SOURCE_DIR_ALGO = ./algorithm
SOURCE_DIR_MOVES = ./moves
SOURCE_DIR_UTILS = ./utils
OBJECTS_DIR = ./obj

SOURCES_ALGO = $(wildcard $(SOURCE_DIR_ALGO)/*.c)
SOURCES_MOVES = $(wildcard $(SOURCE_DIR_MOVES)/*.c)
SOURCES_UTILS = $(wildcard $(SOURCE_DIR_UTILS)/*.c)
SOURCES_MAIN = main.c

SOURCES = $(SOURCES_ALGO) $(SOURCES_MOVES) $(SOURCES_UTILS) $(SOURCES_MAIN)


OBJECTS = $(patsubst ./algorithm/%.c,$(OBJECTS_DIR)/algorithm/%.o,$(SOURCES_ALGO)) \
          $(patsubst ./moves/%.c,$(OBJECTS_DIR)/moves/%.o,$(SOURCES_MOVES)) \
          $(patsubst ./utils/%.c,$(OBJECTS_DIR)/utils/%.o,$(SOURCES_UTILS)) \
          $(OBJECTS_DIR)/main.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./libft 

all : $(NAME)

$(LIBFT_A):
	make -C$(LIBFT) && printf "Compiled $(LIBFT_A)\n"

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)
	mkdir -p $(OBJECTS_DIR)/algorithm
	mkdir -p $(OBJECTS_DIR)/moves
	mkdir -p $(OBJECTS_DIR)/utils

$(OBJECTS_DIR)/algorithm/%.o: ./algorithm/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(OBJECTS_DIR)/moves/%.o: ./moves/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(OBJECTS_DIR)/utils/%.o: ./utils/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(OBJECTS_DIR)/%.o: %.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(LIBFT_A)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_A) -o $(NAME) && printf "Compiled $(NAME)\n"

clean:
		rm -rf $(OBJECTS_DIR)
		make -C $(LIBFT) clean

fclean:	clean
		rm -rf $(NAME)
		make -C $(LIBFT) fclean
		rm -rf $(OBJECTS_DIR)

re:		fclean all