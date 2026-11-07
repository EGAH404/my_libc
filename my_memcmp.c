#include <stddef.h>

int
my_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char *s1 = b1;
	const unsigned char *s2 = b2;

	while (len--) {
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}