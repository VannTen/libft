#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Rules.mk                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/13 19:41:31 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/15 16:02:02 by mgautier         ###   ########.fr       *#
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
			ft_lstmap.c ft_lstnew.c ft_lstpop.c
LST_FUNCT = f_add_end_lst.c f_lstiter.c f_strljoin.c f_strsplit_lst.c
DB_FUNCT = database.c

SRC := $(PART_1) $(PART_2) $(LIST_FUNCT) $(LST_FUNCT) $(DB_FUNCT)

# Standard expansion of the SRC into the local OBJ and DEP
# + add them to clean-up vairables

OBJ_$(DIR) := $(OBJ)
DEP_$(DIR) := $(DEP)
TARGET_$(DIR) := $(DIR)$(TARGET)
CLEAN += $(OBJ_$(DIR))
FCLEAN += $(TARGET_$(DIR)) $(DEP_$(DIR))


-include $(DEP_$(DIR))

#
#Local rules
#

$(TARGET): $(OBJ_$(DIR))
	$(LINK_STATIC_LIB)

OBJ_$(DIR): CFLAGS_TGT := -iquote$(DIR)$(HEADER_DIR)
