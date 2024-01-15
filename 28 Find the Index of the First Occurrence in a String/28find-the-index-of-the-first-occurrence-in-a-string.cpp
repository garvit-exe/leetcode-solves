class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        for (index = 0; index < haystack.length(); index++) {
            if (haystack[index] == needle[0]) {
                int i = index;
                int j = 0;
                while (j < needle.length()) {
                    if (haystack[i] == needle[j]) {
                        i++;
                        j++;
                    } else {
                        break;
                    }
                }
                if (j == needle.length()) {
                    return index;
                }
            }
        }
        return -1;
    
    }
};