class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr) return false;
        if (*string == '+' || *string == '-') {
            ++string;
        } else if (!isNum(*string) && *string != '.')
            return false;
        int head_num = 0;
        while(isNum(*(string))) {
            ++string;
            ++head_num;
        }
        if (*string == '\0' && head_num > 0) return true;
        else if (*string == '.') {
            ++string;
            if ((head_num > 0 && *string == '\0') || (!isNum(*string) && *string != 'e' && *string != 'E'))
                return false;
            while (isNum(*(string)))
                ++string;
            if (*string == 'e' || *string == 'E') {
                ++string;
                if (*string != '+' && *string != '-' && !isNum(*(string)))
                    return false;
                else
                    ++string;
                while (isNum(*(string)))
                    ++string;
            }
            if (*string == '\0') return true;
            else return false;
        } else if (*string == 'e' || *string == 'E') {
            ++string;
            if (*string != '+' && *string != '-' && !isNum(*(string)))
                return false;
            else
                ++string;
            while (isNum(*(string)))
                ++string;
            if (*string == '\0') return true;
            else return false;
        } else return false;
    }

    bool isNum(char ch) {
        int dist = ch - '0';
        if (dist >= 0 && dist <= 9) return true;
        else return false;
    }
};