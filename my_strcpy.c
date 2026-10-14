#include "my_libc.h"

char *
my_strcpy(char *dst, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
<<<<<<< HEAD
}
=======
}
>>>>>>> 80b33a4 (Sauvegarde my_libc)
