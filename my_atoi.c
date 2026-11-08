int
my_atoi(const char *nptr)
{
	int sign = 1;
	int result = 0;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+') {
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
