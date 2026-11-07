#include <stddef.h>

size_t
my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;
	size_t srclen = 0;

	while (src[srclen])
		srclen++;
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < dstsize - 1) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}