#include <stddef.h>

char *
my_strncat(char *dst, const char *src, size_t n)
{
	size_t php = 0;
	size_t is_capout = 0;

	while (dst[php])
		php++;
	while (src[is_capout] && is_capout < n) {
		dst[php] = src[is_capout];
		php++;
		is_capout++;
	}
	dst[php] = '\0';
	return (dst);
}