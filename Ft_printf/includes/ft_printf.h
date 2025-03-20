#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);

int		ft_write_int(int n);

int		ft_write_char(char c);

int		ft_write_str(char *str);

int		ft_write_uint(unsigned int n);

int		ft_write_hex(unsigned int n, char *base);

int		ft_write_ptr(void *ptr);

int		ft_printf(const char *input, ...);

int		zero(void);

int		ft_int_len(int nbr);

int		ft_hex_len(unsigned int nbr);

int		ft_uint_len(unsigned int nbr);

#endif
