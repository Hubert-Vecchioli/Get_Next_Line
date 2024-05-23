/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:21:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/23 11:21:51 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char 	*str;
	char 	*str2;
	int	fd;
	int	fd2;
	int	i;

	fd = 0;
	i = 0;
    fd = 0;
    fd2 = open("./bible.txt", O_RDONLY);
    str = "test";
    str2 = "test";

	while (str)
	{
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		i++;
		printf("Open A #%d -> %d | %s\n", i, fd, str);
		printf("Open B #%d -> %d | %s\n", i, fd2, str2);
	}
}

