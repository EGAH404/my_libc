#include <stddef.h>

void *
my_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	while (len--)
		*d++ = *s++;
	return (dst);
}