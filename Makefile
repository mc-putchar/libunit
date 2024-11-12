NAME := libunit.a
LIBFT := libft/libft.a

.PHONY: framework test clean fclean
$(NAME): | framework
	ln -sf framework/$@ $@
framework:
	@$(MAKE) -C $@

test: $(NAME) $(LIBFT)
	@$(MAKE) -C tests test
	@$(MAKE) -C real-tests test
$(LIBFT):
	@$(MAKE) -C libft || \
	(git submodule update --init --recursive && $(MAKE) -C libft)

clean:
	@$(MAKE) -C framework $(MAKECMDGOALS)
	@$(MAKE) -C libft $(MAKECMDGOALS)
	@$(MAKE) -C tests $(MAKECMDGOALS)
	@$(MAKE) -C real-tests $(MAKECMDGOALS)
	@rm -fr $(NAME)
fclean:
	@$(MAKE) -C framework $(MAKECMDGOALS)
	@$(MAKE) -C libft $(MAKECMDGOALS)
	@$(MAKE) -C tests $(MAKECMDGOALS)
	@$(MAKE) -C real-tests $(MAKECMDGOALS)
	@rm -fr $(NAME)
re: fclean $(NAME)
