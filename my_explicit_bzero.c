#include <stddef.h>

void
my_explicit_bzero(void *buf, size_t len)
{
	volatile unsigned char *p = buf;

	while (len--)
		*p++ = 0;
}