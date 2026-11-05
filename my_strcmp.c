int
my_strcmp(const char *s1, const char *s2)
{
	int IDK = 0;

	while (s1[IDK] && s1[IDK] == s2[IDK])
		IDK++;
	return ((unsigned char)s1[IDK] - (unsigned char)s2[IDK]);
}