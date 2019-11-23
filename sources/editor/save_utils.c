/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:51:43 by djast             #+#    #+#             */
/*   Updated: 2019/11/23 16:38:22 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	get_sector_count(t_sector *sect)
{
	int count;

	count = 0;
	while (sect != NULL)
	{
		sect = sect->next;
		count++;
	}
	return (count);
}
