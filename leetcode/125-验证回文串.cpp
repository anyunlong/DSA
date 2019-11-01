bool isValidChar(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
}

char convertToLowercase(char c) {
    if (c >= 97 && c <= 122) {
        return c;
    }
    if (c >= 65 && c <= 90) {
        return c + 32;
    }
    return c;
}

bool isPalindrome(char * s){
    unsigned long length = strlen(s);
    if (length == 0) {
        return true;
    }
    unsigned long firstIndex = 0;
    unsigned long secondIndex = length - 1;
    while (firstIndex < secondIndex) {
        while (firstIndex < secondIndex) {
            if (isValidChar(s[firstIndex])) {
                break;
            } else {
                firstIndex++;
            }
        }
        while (firstIndex < secondIndex) {
            if (isValidChar(s[secondIndex])) {
                break;
            } else {
                secondIndex--;
            }
        }
        if (firstIndex < secondIndex) {
            if (convertToLowercase(s[firstIndex]) == convertToLowercase(s[secondIndex])) {
                secondIndex -= 1;
                firstIndex += 1;
                continue;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
    return true;
}
