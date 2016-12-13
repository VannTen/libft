#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Rules.mk                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/13 19:41:31 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/13 20:10:22 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

#
# Local part (to be moved in Rules.mk)
#

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
LIST_FUNCT = ft_lstadd.c ft_lstcheck.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
			ft_lstmap.c ft_lstnew.c ft_lstpop.c ft_lstpopdata.c ft_lstpush.c \
			ft_lstpushdata.c
LST_FUNCT = f_add_end_lst.c f_lstiter.c f_strljoin.c f_strsplit_lst.c
DB_FUNCT = database.c

SRC := $(PART_1) $(PART_2) $(LIST_FUNCT) $(LST_FUNCT) $(DB_FUNCT)
OBJ_$(DIR) := $(addprefix $(DIR),$(OBJ))
DEP_$(DIR) := $(addprefix $(DIR),$(DEP))
DEPDIR_LOC := $(DIR)$(DEPDIR)

CLEAN += $(OBJ_$(DIR)) $(DEP_$(DIR))
FCLEAN += $(TARGET_$(DIR))

#
# Local rules
#

OBJ_$(DIR): CFLAGS_TGT := -iquote$(DIR)$(HEADER_DIR)

TEST_OBJ = main.c tests.c list_test.c

ARCH_MEMBER := $(TARGET)($(SRC:.c=.o)) 
TEST_TARGET = my_test
TEST_DIR = ./test
HEADERS = libft.h
HEADERS_TEST = tests.h
