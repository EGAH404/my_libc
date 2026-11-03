char *my_strcat(char *dst, const char *src )

{
    int php = 0;
    int is_dead = 0;
   
    
    while (dst[php])
    php++;

    while (src[is_dead])



  {
        dst[php] = src[is_dead];
        php++;
        is_dead++;
    }
    dst[php]= '\0';

    return (dst);

}