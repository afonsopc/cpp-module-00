NAME	= account
SRC		= tests.cpp Account.cpp
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re