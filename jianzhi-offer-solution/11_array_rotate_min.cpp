class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        int left = 0, right = rotateArray.size()-1, pivot;
        while(left < right){
            pivot = left + (right - left) / 2;
            if(rotateArray[pivot] > rotateArray[right]){
                left = pivot + 1;
            }else if(rotateArray[pivot] == rotateArray[right]){
                --right;
            }else{
                right = pivot;
            }
        }
        return rotateArray[left];
    }
};