SERVER = server
CLIENT = client
CLIENT_BONUS = client_bonus 
SERVER_BONUS = server_bonus
CC = cc

INCLUDE = minitalk.h

CFLAGS = -Wall -Wextra -Werror

serv_sources = server.c tools.c
cl_sources = client.c tools.c

serv_sources_b = server_bonus.c tools.c
cl_sources_b = client_bonus.c tools.c


objet_1 = $(serv_sources:%.c=%.o)
objet_2 = $(cl_sources:%.c=%.o)
objet_b1 = $(serv_sources_b:%.c=%.o)
objet_b2 = $(cl_sources_b:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(objet_1)
	$(CC) $(CFLAGS) $(objet_1) -o $(SERVER) 
$(CLIENT): $(objet_2)
	$(CC) $(CFLAGS) $(objet_2) -o $(CLIENT)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(objet_b1)
	$(CC) $(CFLAGS) $(objet_b1) -o $(SERVER_BONUS) 
$(CLIENT_BONUS): $(objet_b2)
	$(CC) $(CFLAGS) $(objet_b2) -o $(CLIENT_BONUS)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(objet_1) $(objet_2) $(objet_b1) $(objet_b2)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re:	fclean all 

.PHONY: clean fclean all bonus
