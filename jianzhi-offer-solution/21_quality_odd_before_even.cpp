class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) return;
        list<int> odd, even;
        for (vector<int>::iterator itr = array.begin(); itr != array.end(); ++itr) {
            if (*itr & 0x1) odd.push_back(*itr);
            else even.push_back(*itr);
        }
        odd.splice(odd.end(), even);
        vector<int> rst{std::make_move_iterator(std::begin(odd)),
                        std::make_move_iterator(std::end(odd))};
        array.swap(rst);
        return;
    }
};