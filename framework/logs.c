/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:48:08 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 23:27:54 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libunit.h"
#include "libft.h"

#define LOGBUF_SIZE	4096

// TODO: Rewrite for multi-source multi-destination with polling
int	open_log(char const *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND);
	if (fd < 0)
		return (throw_error(-1, "Error: could not open file specified.\n"));
	return (fd);
}

void	handle_log(int log, int pipe, char const *prefix)
{
	static char	logbuf[LOGBUF_SIZE];
	ssize_t		rb;
	ssize_t		wb;
	ssize_t		lb;

	if (log < 0)
		return ;
	lb = 0;
	if (prefix)
		ft_dprintf(log, "%s\n", prefix);
	while (1)
	{
		rb = read(pipe, logbuf, LOGBUF_SIZE);
		if (rb < 1)
			return ;
		while (lb < rb)
		{
			wb = write(log, logbuf, (size_t)(rb - lb));
			if (wb < 1)
				return ;
			lb += wb;
		}
	}
}
