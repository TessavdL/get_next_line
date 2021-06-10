# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tevan-de <tevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/10 11:40:24 by tevan-de      #+#    #+#                  #
#    Updated: 2021/06/10 15:40:48 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libget_next_line.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFILES		=	get_next_line.c					\
				get_next_line_utils.c

BONUSCFILES	=	get_next_line_bonus.c			\
				get_next_line_utils_bonus.c

OFILES		=	${CFILES:%.c=%.o}

BONUSOFILES	=	${BONUSCFILES:%.c=%.o}

HEADERFILES	=	../get_next_line.h

ifdef BONUS
OFILES = ${BONUSCFILES:%.c=%.o}
HEADERFILES = get_next_line_bonus.h
endif

ifdef DEBUG
CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

bonus:
	@$(MAKE) BONUS=1 all

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Created $(NAME)"

%.o: %.c $(HEADERFILES)
	@echo "Compiling: $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "Cleaning all object files"
	@/bin/rm -f $(OFILES) $(BONUSOFILES)

fclean: clean
	@echo "Cleaning $(NAME)"
	@/bin/rm -f $(NAME)

re:	fclean all
