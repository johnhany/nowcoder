/*
    NOTE: Arg `length` is not size of string, it's capacity of string.
*/

class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == nullptr || length == 0) return;
        int count = 0, len = 0;
        char* cur = str;
        for (; *cur != '\0'; ++cur) {
            ++len;
            if (*cur == ' ') ++count;
        }
        int newLen = len + count*2;
        if (newLen > length) return;
        char* tar = str+newLen;
        while (true) {
            if (*cur == ' ') {
                *(tar--) = '0';
                *(tar--) = '2';
                *tar = '%';
            } else
                *tar = *cur;
            if (tar == str) break;
            else --cur, --tar;
        };
        return;
	}
};