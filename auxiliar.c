//http://stackoverflow.com/questions/5457608/how-to-remove-a-character-from-a-string-in-c
void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}
