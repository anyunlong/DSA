
int titleToNumber(char * s){
    int length = strlen(s);
    if (s == NULL || length == 0) {
        return 0;
    }
    int number = 0;
    for (int index = length - 1; index >= 0; --index) {
        char AInt = 'A';
        int charAInt = AInt;
        printf("%d", charAInt);
        int indexCharInt = s[index];
        printf("%d", indexCharInt);
        int x = indexCharInt - charAInt + 1;
        printf("%d", x);
        number = x * pow(26, length - index - 1) + number;
    }
    return number;
}
