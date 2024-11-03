# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 19:13:42 by mcutura           #+#    #+#              #
#    Updated: 2024/11/03 23:27:47 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libunit.a
HEADER := libunit.h
SRCS := libunit logs signals test unit
BINS := $(SRCS:%=%.o)

LIBFTDIR := ../libft
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic -Wconversion -Wshadow
CPPFLAGS := -I. -I$(LIBFTDIR)/include
debug: CFLAGS += -ggdb3 -Og
debug: CPPFLAGS += -DDEBUG
bonus: CPPFLAGS += -DCOLOR_PRINT=1
AR := ar
ARFLAGS := src

.PHONY: all bonus clean debug fclean help re

all: bonus	# Compile all target binaries
debug: all	# Compile for debugging
bonus: $(NAME)	# Compile with bonuses

$(NAME): $(LIBFT) $(HEADER) $(BINS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:	# Remove compiled intermediary binaries
	rm -fr $(BINS)
fclean: clean	# Remove all compiled binaries
	rm -fr $(NAME)
re: fclean all	# Recompile all target binaries
help:	# Show help for this Makefile
#TODO: get help
