#include "monty.h"
/**
 * _strcmp - compares two strings.
 * @s1: first string compared
 * @s2: second string compared
 * Return: 0 if s1 and s2 are equal
 *
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;
	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}

/**
 * _sch - search for a char inside a string
 * @s: string to traverse
 * @c: char to find
 * Return: 1 if success 0 if it fails
 */
int _sch(char *s, char c)
{
	int count = 0;

	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			break;
		}
		count++;
	}
	if (s[count] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - cuts string into tokens depending of the delimiter
 * @s: string to cut
 * @d: delimiters
 * Return: 1st partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultim;
	int x = 0, y = 0;

	if (!s)
		s = ultim;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			ultim = s + x + 1;
			*ultim = '\0';
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultim = s + x + 1;
			*ultim = '\0';
			ultim++;
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
