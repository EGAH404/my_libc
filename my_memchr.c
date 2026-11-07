#include <stddef.h>

void *
my_memchr(const void *b, int c, size_t len)
{
	const unsigned char *p = b;

	while (len--) {
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}