#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Rules.mk                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/13 19:41:31 by mgautier          #+#    #+#             *#
#*   Updated: 2017/01/10 18:12:01 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

##
## Rules.mk
## One instance of this file is included for every subdirectory of the project
## which produces one target (directory that hold specific type of files, such
## as source directory, includes directory, or objetc directory, aren't concerned
##
STACK_POINTER := $(STACK_POINTER).x
DIR_$(STACK_POINTER) := $(DIR)
DIR := $(DIR)$(SUBDIR)

# Inlcudes Srcs.mk, which defines directory data (source files, target name,
# additional dependencies, libraries needed)
# Clean variables before, so we dont catch some from a previous dir
# if there is a problem with Srcs.mk

$(foreach VARIABLE,$(EMPTY_SRCS.MK),$(eval $(VARIABLE):= ))
include $(DIR)Srcs.mk

# Give the full path to the locals directories (by appending DIR before them)
# add a slash only if necessary (alway adding a slash cause trouble in the top level
# directory if subdirs are not defined (which means SRC_DIR (or another one)= DIR)

$(foreach TYPE,SRC OBJ DEP INC,$(eval $(call ADD_SLASH,$(TYPE))))

# Add the obj and dependency dir to the list of generated dir
# only if they are different from the DIR (which is not generated)

ifdef OBJ_DIR
GENERATED_SUBDIRS += $(OBJ_LOCAL_$(DIR))
endif
ifdef DEP_DIR
GENERATED_SUBDIRS += $(DEP_LOCAL_$(DIR))
endif

# Standard expansion of the SRC into the local OBJ and DEP
# + add them to clean-up variables

OBJ_$(DIR) := $(OBJ)
DEP_$(DIR) := $(DEP)

# + check if the target of this directory is indicated
# If it is, a vpath directive allow rules that use that target
# as a prerequisites to locate it easily

ifdef TARGET
TARGET_$(DIR) := $(DIR)$(TARGET)
vpath $(TARGET) $(DIR)
$(basename $(TARGET))_PATH := $(DIR)
else
$(eval $(TARGET_ERROR))
endif

# If the target is a static library, use the approriate recipe.
# Otherwise, use the linker for an executable

ifeq ($(suffix $(TARGET)),.a)
$(TARGET_$(DIR)): RECIPE = $(LINK_STATIC_LIB)
LIBPATH_INC += $(DIR)
else ifeq ($(suffix $(TARGET)),.so)
$(TARGET_$(DIR)): RECIPE = $(LINK_SHARED_LIB)
LIBPATH_INC += $(DIR)
else
$(TARGET_$(DIR)): RECIPE = $(LINK_EXE)
endif

# Local rules

$(TARGET_$(DIR)): $(OBJ_$(DIR)) $(ELSE) $(subst lib,-l,$(LIBRARIES))
	$(QUIET) $(RECIPE)

$(eval $(STATIC_OBJ_RULE))

# If the target is different from the one make is invoked in,
# add it to the search path for headers.
# If the target requiers a library, add its directory too.

$(TARGET_$(DIR)): DIR := $(DIR)
$(TARGET_$(DIR)): INCLUDE := $(INC_LOCAL_$(DIR))

ifdef LIBRARIES
$(DIR)_LIBS := $(LIBRARIES)
$(TARGET_$(DIR)): LIB_INCLUDES = $(foreach XXX,$($(DIR)_LIBS),$($(XXX)_PATH))
endif

# Clean variables 
# If this is not the top level (the one where make is invoked) do add the Makefile
# and the Rules.mk files to MKCLEAN
# That way, we're sure that not all Makfiles can be erased.

CLEAN += $(OBJ_$(DIR))
FCLEAN += $(TARGET_$(DIR)) $(DEP_$(DIR))
ifneq ($(DIR),)
MKCLEAN += $(DIR)Makefile $(DIR)Rules.mk
endif

# Inclusion of depency files (auto-generated)

DEP_FILES+= $(DEP_$(DIR))

# Inclusion of subdirs Rules.mk

$(foreach SUBDIR,$(addsuffix /,$(SUBDIRS)),$(eval $(INCLUDE_SUBDIRS)))

# Tracking current directory

DIR := $(DIR_$(STACK_POINTER))
STACK_POINTER := $(basename $(STACK_POINTER))
