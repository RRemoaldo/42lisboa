/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:47:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 09:47:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char ft_strcat(char *str1, char *str2, int n)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j] != '\0' && j <= n)
    {
        str1[i + j] = str2[j]
        j++;
    }
    str1[i + j] = '\0';
    return (str1);
}