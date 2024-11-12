NAME := unit_test
SRCS := main
SRCS += $(addprefix dummy/, \
	00_launcher \
	01_test_ok \
	02_test_ko \
	03_test_segfault \
	04_test_buserr \
)
SRCS += $(addprefix bonus/, \
	00_launcher \
	01_test_abort \
	02_test_fpe \
	03_test_piperr \
	04_test_illegal \
	05_expected_fail_test \
	06_timeout_test \
	07_unexpected_pass_test \
)
SRCS += $(addprefix strlen/, \
	00_launcher \
	01_basic_test \
	02_null_test \
	03_bigger_str_test \
	04_failing_test \
)
BINS := $(SRCS:%=%.o)
LIBUNITDIR := ../framework
LIBUNIT := $(LIBUNITDIR)/libunit.a
LIBFTDIR := ../libft
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic -Wconversion -Wshadow
CPPFLAGS := -I$(LIBUNITDIR) -I$(LIBFTDIR)/include
LDFLAGS := -L$(LIBUNITDIR) -L$(LIBFTDIR)
LDLIBS := -lunit -lft
debug: CFLAGS += -ggdb3 -Og
debug: CPPFLAGS += -DDEBUG

.PHONY: all clean debug fclean re test
all: $(NAME)
debug: all
$(NAME): $(LIBUNIT) $(BINS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(BINS) -o $@ $(LDFLAGS) $(LDLIBS)
$(LIBUNIT):
	$(MAKE) -C $(LIBUNITDIR)
$(BINS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
clean:
	rm -fr $(BINS)
fclean: clean
	rm -fr $(NAME)
re: fclean all
test:
	@$(MAKE) all --silent && ./$(NAME)
