NAME = lib42.a
CC ?= clang
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -std=c99 -pedantic -pedantic-errors
ifeq ($(shell readlink $(shell command -v $(CC))),clang)
	CFLAGS += -Weverything -Wno-missing-noreturn
endif
CFLAGS += -fno-strict-aliasing

# Debug
ifeq ($(DEBUG),yes)
	CFLAGS += -g3 -O0 -fno-inline
endif

# Profile
ifeq ($(PROF),yes)
	CFLAGS += -pg
endif

# Opti
ifeq ($(PROD),yes)
	CFLAGS += -O2
endif

# Sanitize
ifeq ($(SAN),yes)
	LDFLAGS += -fsanitize=address
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

# Memory
SRC_SUBDIR += memory
SOURCES += ft_memset.c
SOURCES += ft_memalloc.c
SOURCES += ft_memcpy.c
SOURCES += ft_memccpy.c
SOURCES += ft_memmove.c
SOURCES += ft_memcmp.c
ifeq ($(SAN),yes)
	SOURCES += ft_memchr_sanitize.c
else
	SOURCES += ft_memchr.c
endif

# Stdlib
SRC_SUBDIR += stdlib
SOURCES += ft_realloc.c
SOURCES += ft_toa_base.c
SOURCES += next_power2.c

# Array
SRC_SUBDIR += array
SOURCES += array_new.c
SOURCES += array_resize.c
SOURCES += array_getset.c
SOURCES += array_indexof.c
SOURCES += array_create_node.c
SOURCES += array_stack.c
SOURCES += array_replace.c
SOURCES += array_insert.c
SOURCES += array_reset.c
SOURCES += array_destroy.c
SOURCES += array_remove.c
SOURCES += array_delete.c
SOURCES += array_strsplit.c
SOURCES += array_iter.c

# Cbuffer
SRC_SUBDIR += cbuffer
SOURCES += cbuffer_new.c
SOURCES += cbuffer_push.c
SOURCES += cbuffer_pop.c
SOURCES += cbuffer_get.c
SOURCES += cbuffer_resize.c

# Buffer
SRC_SUBDIR += string
SOURCES += string_init.c
SOURCES += string_dup.c
SOURCES += string_cat.c
SOURCES += string_destroy.c
SOURCES += string_insert.c
SOURCES += string_merge.c
SOURCES += string_remove.c
SOURCES += string_replace.c
SOURCES += string_resize.c
SOURCES += string_rewind.c
SOURCES += string_set.c
SOURCES += string_toa.c
SOURCES += string_twin.c
SOURCES += string_append.c

# String
SRC_SUBDIR += str
SOURCES += ft_strcmp.c
SOURCES += ft_strlen.c
SOURCES += ft_strdup.c
SOURCES += ft_strsub.c
SOURCES += ft_strchr.c
SOURCES += ft_strrchr.c
SOURCES += ft_strrev.c
SOURCES += ft_strstr.c
SOURCES += ft_strrstr.c
SOURCES += ft_strtolower.c
SOURCES += ft_strtoupper.c

# Pool
SRC_SUBDIR += pool
SOURCES += pool_new.c
SOURCES += pool_chunk.c
SOURCES += pool_obtain.c
SOURCES += pool_return.c
SOURCES += pool_reset.c
SOURCES += pool_destroy.c

# Error
SRC_SUBDIR += error
SOURCES += ft_error.c
SOURCES += ft_die.c

# Printf
SRC_SUBDIR += printf
SOURCES += ft_printf.c
SOURCES += ft_printf_core.c
SOURCES += ft_dprintf.c
SOURCES += ft_asprintf.c
SOURCES += ft_snprintf.c
SOURCES += ft_sprintf.c
SOURCES += conv_c.c
SOURCES += conv_s.c
SOURCES += conv_wc.c
SOURCES += conv_wcs.c
SOURCES += conv_d.c
SOURCES += conv_uo.c
SOURCES += conv_x.c
SOURCES += conv_prc.c
SOURCES += utf8.c
SOURCES += str_formatting.c
SOURCES += int_formatting.c
SOURCES += parsing.c
SOURCES += utils.c

# Unistd
INC_FILES += unistd_42.h
SRC_SUBDIR += unistd
SOURCES += ft_getopt.c

# Generation
INC_PATH = inc
SRC_PATH = src
CFLAGS += $(addprefix -I,$(INC_PATH))
vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

# Object files
OBJ_PATH = .obj
OBJECTS = $(SOURCES:%.c=$(OBJ_PATH)/%.o)

# Dependencies
DEP_PATH = .dep
DEPS = $(SOURCES:%.c=$(DEP_PATH)/%.d)

BUILD_DIR = $(OBJ_PATH) $(DEP_PATH)

# Tests
TEST_PATH = test
TEST_EXEC = $(TEST_PATH)/test_lib42.out
GIT_CLEAN = git clean -fd

# Rules
.PHONY: all

.SECONDARY: $(OBJECTS)

all: $(DEPS) $(NAME)

-include $(DEPS)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

$(OBJECTS): $(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(DEP_PATH)/%.d: %.c | $(DEP_PATH)
	$(CC) $(CFLAGS) -MM $< -MT $(OBJ_PATH)/$*.o -MF $@

$(BUILD_DIR):
	@-mkdir -p $@

.PHONY: clean fclean re sanitize unsanitize

clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

sanitize:
	$(MAKE) -C ./ re SAN=yes DEBUG=yes

unsanitize:
	$(MAKE) -C ./ re DEBUG=yes

# Submodule
.PHONY: sub-update sub-init

sub-init:
	git submodule update --init --recursive

sub-update:
	git submodule update --remote --recursive

# Tests
.PHONY: check test-cleanup

check: all
	@$(MAKE) -C $(TEST_PATH) re
	@./$(TEST_EXEC)

# Tools
.PHONY: norme valgrind ctags clean-tools

norme:
	@ ! norminette -R CheckTopCommentHeader $(SRC_PATH) | grep -v -B 1 "^Norme"
	@ ! norminette -R CheckTopCommentHeader $(INC_PATH) | grep -v -B 1 "^Norme"

valgrind:
	valgrind --leak-check=full ./$(NAME)

callgrind:
	valgrind --tool=callgrind --callgrind-out-file=$(CG_OUTPUT_FILE) ./$(NAME)
	callgrind_annotate --auto=yes $(CG_OUTPUT_FILE)

ctags:
	ctags -R --tag-relative=yes --exclude='.git*' --exclude='test' --exclude='*.o' --exclude='*dSYM' --exclude='doc' --exclude='exercices'

clean-tools:
	$(RM) -r *.dSYM/
