#include <stddef.h>

char *
my_strrchr(const char *s, int c)
{
	char *last = NULL;

	while (*s) {
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}