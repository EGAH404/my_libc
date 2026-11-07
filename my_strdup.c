#include <stdlib.h>
#include <stddef.h>

char *
my_strdup(const char *s)
{
	size_t len = 0;
	char *dup;

	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len]) {
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}