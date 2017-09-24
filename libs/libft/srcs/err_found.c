/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:32:46 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/09 20:14:07 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		err_found(char *str)
{
	ft_putendl_fd(str, 2);
	exit(3);
}