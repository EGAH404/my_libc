#include <errno.h>
#include <limits.h>
#include <stddef.h>

static int
char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

long
my_strtol(const char *nptr, char **endptr, int base)
{
	long result = 0;
	int sign = 1;
	int digit;
	int overflow = 0;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+') {
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (base < 0 || base == 1 || base > 36) {
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	if (base == 0) {
		if (*nptr == '0') {
			if (nptr[1] == 'x' || nptr[1] == 'X')
				base = 16;
			else
				base = 8;
		} else {
			base = 10;
		}
	}
	if (base == 16 && *nptr == '0') {
		if (nptr[1] == 'x' || nptr[1] == 'X')
			nptr += 2;
	}
	const char *start = nptr;
	while ((digit = char_to_digit(*nptr)) >= 0 && digit < base) {
		if (!overflow) {
			long cutoff;
			if (sign == 1) {
				cutoff = (LONG_MAX - digit) / base;
				if (result > cutoff)
					overflow = 1;
			} else {
				cutoff = (LONG_MIN + digit) / base;
				if (-result < cutoff)
					overflow = 1;
			}
			if (!overflow)
				result = result * base + digit;
		}
		nptr++;
	}
	if (endptr) {
		if (nptr == start)
			*endptr = (char *)start;
		else
			*endptr = (char *)nptr;
	}
	if (overflow) {
		errno = ERANGE;
		if (sign == 1)
			return (LONG_MAX);
		return (LONG_MIN);
	}
	return (result * sign);
}