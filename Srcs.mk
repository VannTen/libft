# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/01/05 16:11:48 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

TARGET := libft.a
SRC := database.c f_add_end_lst.c f_lstiter.c f_strljoin.c f_strsplit_lst.c \
	ft_add_end_list.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstcheck.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	f_lstpop.c  ft_lstpushdata.c ft_memalloc.c ft_memset.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c \
	f_lstpush.c f_lstnew.c f_lst_every_valid.c f_lstmap.c f_lstdelone.c f_lstdel.c \
	f_lstmapi.c f_lst_len.c f_lstsearch.c\
	f_fifo_add.c f_fifo_create.c f_fifo_take.c f_fifo_destroy.c f_fifo_extract.c \
	ft_free_string_array.c \
	ft_int_square_root.c

# Dependencies

LIBRARY := 
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS :=
