class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        
        if (source == NULL || target == NULL) {
            return -1;
        }
        
        if (strlen(source) == 0 && strlen(target) == 0) {
            return 0;
        }
        
        if (strlen(source) == 0 && strlen(target) != 0) {
            return -1;
        }
        
        if (strlen(source) != 0 && strlen(target) == 0) {
            return 0;
        }
        
        if (strlen(source) < strlen(target)) {
            return -1;
        }
        
        int i = 0;
        int j = 0;
        
        while (i < strlen(source)) {
            if (source[i] == target[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
            
            if (j == strlen(target)) {
                return i - j;
            }
        }
        
        return -1;
    }
};
