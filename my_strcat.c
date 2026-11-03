char	*my_strcat(char *dst, const char *src)
{
	int	php = 0;
	int	is_capout = 0;

	while (dst[php])
		php++;
	while (src[is_capout]) {
		dst[php] = src[is_capout];
		php++;
		is_capout++;
	}
	dst[php] = '\0';
	return (dst);
}