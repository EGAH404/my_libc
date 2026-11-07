#include <stddef.h>

static int
is_delim(char c, const char *delim)
{
	while (*delim) {
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char *
my_strtok(char *str, const char *delim)
{
	static char *save;
	char *token;

	if (str)
		save = str;
	if (!save)
		return (NULL);
	while (*save && is_delim(*save, delim))
		save++;
	if (!*save) {
		save = NULL;
		return (NULL);
	}
	token = save;
	while (*save && !is_delim(*save, delim))
		save++;
	if (*save) {
		*save = '\0';
		save++;
	} else {
		save = NULL;
	}
	return (token);
}