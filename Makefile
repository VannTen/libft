#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/15 18:13:01 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


#
# General variables (compiling and such). Will be kept in the local Makefile
#

.SUFFIXES:

.DEFAULT_GOAL:= all
# Static libary maintainer
# -U option is to be sure that library is created in non-deterministic mode
#  (aka with a timestamp which is not set to 0)
AR = ar 
ARFLAGS = rc
LINK_STATIC_LIB = $(AR) $(ARFLAGS) $@ $?

CC = gcc
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic-errors
CFLAGS += $(CFLAGS_TGT)

DEPFLAGS = -MT $(notdir $@) -MP -MMD -MF $(word 2,$^)T

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@
POSTCOMPILE = echo -E "s/[a-z],.,_,:]+/\$$(DIR)&/g" $(word 2,$^)T > $(word 2,$^)
$(info $(POSTCOMPILE))
DIR = ./

# These variables are used to obtain the .o and .dep files
# for each level of the projet, by using the current value of SRC.

OBJ = $(patsubst %.c,$(DIR).%.o,$(SRC))
DEP = $(patsubst %.c,$(DIR).%.dep,$(SRC))

# Clean-up variables
# Collect all the files that need to be deleted along all the project tree
# the clean-up rules then use them to do their job

CLEAN :=
FCLEAN :=


#
# Compilation rule
# Generate dependencies as a side effet
# 

%.o: %.c
.%.o: %.c .%.dep
	$(COMPILE) $<
	$(POSTCOMPILE)

%.dep: ;

.PRECIOUS: %.dep
.SECONDARY: %.d
.SECONDARY: %.o

include Rules.mk

#
# Mandatory rules
#

all: $(TARGET)

clean:
	$(RM) $(CLEAN)

fclean: clean
	$(RM) $(FCLEAN)

re: fclean all

debug: CFLAGS+=-g -pg

debug: $(TARGET)

.PHONY: debug all clean fclean re
