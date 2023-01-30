#include "../cub3d.h"

void	my_print(char *str)
{
	while (*str)
		write(2, str++, 1);
}