#include <stddef.h>

void *
my_memset(void *b, int c, size_t len)
{
	unsigned char *p = b;

	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}