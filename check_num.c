#include "monty.h"

/**
 * check_num - check if a given ching is a number
 * @ch: the ching to check
 * Return: 1 if num, otherwise 0
*/

int check_num(char *ch)
{
	int i = 0;

	if (ch == NULL || *ch == '\0')
	{
		return (0);
	}
	if (ch[0] == '-')
	{
		i = 1;
	}
	for (; ch[i] != '\0'; i++)
	{
		if (!isdigit(ch[i]))
		{
			return (0);
		}
	}
	return (1);
}
