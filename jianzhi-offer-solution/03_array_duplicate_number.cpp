class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length <= 0) return false;
        for (int i = 0; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] >= length) return false;
            if (numbers[i] == i) continue;
            else if (numbers[numbers[i]] == numbers[i]) {
                *duplication = numbers[i];
                return true;
            } else std::swap(numbers[numbers[i]], numbers[i]);
        }
        return false;
    }
};