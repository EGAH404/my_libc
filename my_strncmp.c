int
my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t IDK = 0;

	if (n == 0)
		return (0);
	while (IDK < n - 1 && s1[IDK] && s1[IDK] == s2[IDK])
		IDK++;
	return ((unsigned char)s1[IDK] - (unsigned char)s2[IDK]);
}