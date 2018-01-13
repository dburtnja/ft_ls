/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:28:03 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 10:00:56 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memalloc_error(size_t size)
{
	void	*ret;

	ret = ft_memalloc(size);
	if (ret == NULL)
	{
		perror(ft_strjoin("Fail to allocate memory with size: ",
					ft_itoa((int)size)));
		exit(-1);
	}
	return (ret);
}
