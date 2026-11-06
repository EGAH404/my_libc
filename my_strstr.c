#include <stddef.h>

char *
my_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack) {
		i = 0;
		while (haystack[i] && haystack[i] == needle[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}