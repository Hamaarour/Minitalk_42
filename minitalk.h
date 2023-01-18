/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:35:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/18 14:11:58 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_putchar(char c);
int			ft_putstr(char *str);
int			count_nbr(unsigned long nbr, int bs, int sign);
int			ft_putnbr(long int nbr);
int			ft_putnbr_hex(unsigned long nbr, char bs);
size_t		ft_strlen(char *str);
int			ft_printf(const char *str, ...);
int			ft_atoi(const char *str);

#endif
