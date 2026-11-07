#include <stddef.h>

size_t
my_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen = 0;
	size_t srclen = 0;
	size_t i = 0;

	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	while (src[i] && dstlen + i < dstsize - 1) {
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
