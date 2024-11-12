NAME := libunit.a

.PHONY: framework test clean fclean
$(NAME): | framework
	ln -sf framework/$@ $@
framework:
	@$(MAKE) -C $@

test: $(NAME)
	@$(MAKE) -C tests test
	@$(MAKE) -C real-tests test

clean:
	@$(MAKE) -C framework $(MAKECMDGOALS)
	@$(MAKE) -C tests $(MAKECMDGOALS)
	@$(MAKE) -C real-tests $(MAKECMDGOALS)
	@rm -fr $(NAME)

fclean:
	@$(MAKE) -C framework $(MAKECMDGOALS)
	@$(MAKE) -C tests $(MAKECMDGOALS)
	@$(MAKE) -C real-tests $(MAKECMDGOALS)
	@rm -fr $(NAME)

re: fclean $(NAME)
