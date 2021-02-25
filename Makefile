##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

CFLAGS = -Wall -Wextra -g3 -I./include

CSFML = -l csfml-graphics -l csfml-window -l csfml-system -l csfml-network -l csfml-audio

SRC	=	main.c \
		lib/my_put_nbr.c \
		lib/my_strcmp.c \
		src/clock_movement.c \
		src/close_window.c \
		src/ending.c \
		src/free_all.c \
		src/game_events.c \
		src/game_launch.c \
		src/init_misc.c \
		src/init_struct.c \
		src/load_file.c \
		src/my_runner.c \
		src/spawn_enemy.c \
		src/start_game.c \
		src/update_positions.c \
		src/upgrade_score.c \
		src/usage.c \
		src/verif_file.c \

OBJ 	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) $(CSFML)
		rm -f *.o src/*.o lib/*.o

clean:
	rm -f $(NAME)
	rm -f *.o src/*.o

fclean: clean

re: fclean all