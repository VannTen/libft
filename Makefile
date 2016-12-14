#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/14 16:09:13 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


#
# General variables (compiling and such). Will be kept in the local Makefile
#

AR = ar 
ARFLAGS = rc

CC = gcc
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic-errors
CFLAGS += $(CFLAGS_TGT)

DEPFLAGS = -MT $@ -MP -MMD $(word 2,$^)T

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
POSTCOMPILE = mv -f $(word 2,$^)T $(word 2,$^)

OBJ_DIR = bin
SRC_DIR = src
DEP_DIR = .dep
DIRECTORIES =

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
#
# General rules (will be specified by user)
#

all: $(TARGET)

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean cleantest
	$(RM) $(TARGET)

re: fclean all

debug: $(TARGET)

debug: CFLAGS+=-g -pg

.PHONY: debug all clean fclean re

#
# General pattern rules
#

.SECONDEXPANSION:

%.o: $$(dir $$(dir $$@))/$(SRC_DIR)/$$(F*).c $$(dir $$(dir $$@))/$(DEP_DIR)/$$(*F).d | $$(dir $$(dir $$@))/$(DEP_DIR) $$(dir $@)
	$(COMPILE) $<
	$(POSTCOMPILE)

$(DIRECTORIES):
	mkdir $@

include Rules.mk
