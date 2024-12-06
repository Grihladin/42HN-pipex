/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:01:53 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 19:25:29 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	i = 0;
	if (dest_size == 0)
	{
		return (ft_strlen(src));
	}
	while (i < dest_size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

static size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	size_to_copy;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_size <= dest_len)
		return (dest_size + src_len);
	size_to_copy = dest_size - dest_len - 1;
	i = 0;
	while (i < size_to_copy && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + s2_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}

char	*free_and_return_empty(char *s)
{
	char	*result;

	result = malloc(sizeof(char));
	result[0] = '\0';
	if (s != NULL)
		free(s);
	return (result);
}

// int	main(void)
// {
// 	int		i;
// 	char	s1[50] = "Michael ";
// 	char	s2[50] = "Ratke";
// 	char	*joincheck;

// 	i = 0;
// 	joincheck = ft_strjoin(s1, s2);
// 	while (joincheck[i] != '\0')
// 	{
// 		printf("%c", joincheck[i]);
// 		i++;
// 	}
// }
