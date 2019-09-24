void reverseString(char* s, int sSize){
    if (sSize < 1 || s == NULL) {
        return;
    }
    
    int maxIndex = sSize / 2;
    for (int index = 0; index < maxIndex; ++index) {
        char temp = s[index];
        s[index] = s[sSize - 1 - index];
        s[sSize - 1 - index] = temp;
    }
}
