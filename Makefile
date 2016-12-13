#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/13 20:08:25 by mgautier         ###   ########.fr       *#
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
COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
POSTCOMPILE = mv -f $(DEPDIR_LOC)/$*.Td $(DEPDIR_LOC)/$*.d
OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)
DEPFLAGS = -MT $@ -MP -MMD $(DEPDIR_LOC)/$*.Td 
DEPDIR = $(DIR)/.d

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

%.o: %.c $(DEPDIR)/%.d | $(DEPDIR)
	$(COMPILE) $<
	$(POSTCOMPILE)

$(DEPDIR):
	$(shell mkdir $(DEPDIR))
#
# Local rules
#

$(TARGET): $(ARCH_MEMBER)
	ranlib $@
# 
# Pattern rules
#

-include $(DEP)

#
# Rules for test
#

cleantest:
	$(RM) $(TEST_TARGET) $(TEST_OBJ)

retest: fclean test

test: $(TEST_TARGET)

$(TEST_TARGET): $(TARGET) $(TEST_OBJ) $(HEADERS_TEST)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -L. -l$(LIB) $(TEST_OBJ)

