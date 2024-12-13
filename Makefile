CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SOURCES = client.c
SERVER_SOURCES = server.c

CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

NAME = client server

all: $(NAME)

server: $(SERVER_SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_OBJECTS) $(SERVER_SOURCES) $(LIBFT)

client: $(CLIENT_SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_OBJECTS) $(CLIENT_SOURCES) $(LIBFT)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re