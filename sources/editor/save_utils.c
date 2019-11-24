/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:51:43 by djast             #+#    #+#             */
/*   Updated: 2019/11/24 10:58:42 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// int	get_sector_count(t_sector *sect)
// {
// 	int count;

// 	count = 0;
// 	while (sect != NULL)
// 	{
// 		sect = sect->next;
// 		count++;
// 	}
// 	return (count);
// }

void		write_to_file(int fd, char *data, int numdata)
{
	data = ft_itoa(numdata);
	write(fd, data, ft_strlen(data));
	free(data);
}
