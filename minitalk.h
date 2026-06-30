/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballalamisse <lamisse.balla@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:33:36 by ballalamisse          #+#    #+#             */
/*   Updated: 2026/07/01 15:35:06 by ballalamisse        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char	*str);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif
