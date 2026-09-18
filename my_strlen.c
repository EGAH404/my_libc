#include "my_libc.h"

size_t
my_strlen(const char *s)
{
        size_t len = 0;

        while (s[len] != '\0') {
                len++;
        }

        return len;
}

//1er code et j'ai deja mal au fesse
