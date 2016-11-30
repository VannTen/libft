#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/11/30 11:14:33 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

LIB = ft
TARGET = lib$(LIB).a
PART_1 = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		 ft_strncat.c ft_strlcat.c ft_strcmp.c ft_strncmp.c ft_memset.c \
		 ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		 ft_memcmp.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		 ft_isascii.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_toupper.c ft_tolower.c
PART_2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		 ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		 ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		 ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c
PART_3 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		 ft_lstmap.c
PART_4 = ft_add_end_list.c
SRC := $(PART_1) $(PART_2) $(PART_3) $(PART_4)
DEP := $(SRC:.c=.d)
OBJ := $(SRC:.c=.o)
TEST_OBJ = main.c tests.c list_test.c


ARCH_MEMBER := $(TARGET)($(SRC:.c=.o)) 
TEST_TARGET = my_test
TEST_DIR = ./test
AR = ar 
ARFLAGS = rc
CC = gcc
HEADERS = libft.h
HEADERS_TEST = tests.h
CFLAGS = -Wall -Wextra -Werror -g

all: $(TARGET)

$(TARGET): $(ARCH_MEMBER)
	ranlib $@
clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean cleantest
	@$(RM) $(TARGET)

re: fclean all

# 
# Implicit rules
#

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

include $(DEP)

#
# Rules for test
#

cleantest:
	@$(RM) $(TEST_TARGET) $(TEST_OBJ)

retest: fclean test

test: $(TEST_TARGET)

$(TEST_TARGET): $(TARGET) $(TEST_OBJ) $(HEADERS_TEST)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -L. -l$(LIB) $(TEST_OBJ)

