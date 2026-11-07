#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <stdint.h>

void *
my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb && size > SIZE_MAX / nmemb) {
		errno = ENOMEM;
		return (NULL);
	}
	return (realloc(ptr, nmemb * size));
}
