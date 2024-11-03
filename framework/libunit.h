/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:20:31 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 23:22:40 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/types.h>

# ifndef COLOR_PRINT
#  define COLOR_PRINT	0
# endif

typedef enum e_status
{
	INIT = 0,
	OK,
	KO,
	TIMEOUT,
	ERRSEGV,
	ERRBUS,
	ERRABRT,
	ERRFPE,
	ERRPIPE,
	ERRILL
}	t_status;

static char const	*g_status_name[] = {
	"INIT",
	"OK",
	"KO",
	"TIMEOUT",
	"SIGSEGV",
	"SIGBUS",
	"SIGABRT",
	"SIGFPE",
	"SIGPIPE",
	"SIGILL"
};

typedef struct s_test
{
	int				(*func)(void);
	char const		*name;
	t_status		status;
	t_status		expect;
	struct s_test	*next;
}	t_test;

typedef struct s_unit
{
	t_test			*tests;
	char const		*func_name;
	int				total;
	int				passed;
	unsigned int	timeout;
	int				pipe;
	int				log;
}	t_unit;

typedef struct s_routine
{
	t_unit		*units;
	char const	*name;
	int			total;
	int			passed;
}	t_routine;

t_unit		*create_test_unit(char const *func_name);
t_unit		*create_timed_test_unit(char const *func_name, unsigned int sec);
int			set_log(t_unit *unit, char const *filepath);
int			add_test(t_unit *unit, char const *test_name, int (*test_f)(void));
int			add_test_expect(t_unit *unit, char const *test_name, \
			int (*test_func)(void), t_status expected);
int			launch_unit(t_unit **test_unit);

// Internal
int			execute_test_unit(t_unit *unit);
int			exec_test(t_test *test, unsigned int timeout, int log);
t_status	get_signal(int sig);
void		output_prerun(char const *func_name, t_test *test);
void		output_result(t_test *test);
void		output_unit_results(t_unit *unit);
void		free_unit(t_unit **unit);
int			open_log(char const *filename);
void		handle_log(int log, int pipe, char const *prefix);

#endif // LIBUNIT_H
