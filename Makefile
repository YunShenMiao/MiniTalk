CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SOURCES = client.c
SERVER_SOURCES = server.c
CLIENT_BSOURCES = client_bonus.c
SERVER_BSOURCES = server_bonus.c

CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
CLIENT_BOBJECTS = $(CLIENT_BSOURCES:.c=.o)
SERVER_BOBJECTS = $(SERVER_BSOURCES:.c=.o)

NAME = client server
BONUS_NAME = client_bonus server_bonus 

all: $(NAME)

server: $(SERVER_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJECTS) $(LIBFT)

client: $(CLIENT_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJECTS) $(LIBFT)

bonus: $(BONUS_NAME)

server_bonus: $(SERVER_BOBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o server_bonus $(SERVER_BOBJECTS) $(LIBFT)

client_bonus: $(CLIENT_BOBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o client_bonus $(CLIENT_BOBJECTS) $(LIBFT)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(CLIENT_OBJECTS) $(SERVER_OBJECTS) $(CLIENT_BOBJECTS) $(SERVER_BOBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re