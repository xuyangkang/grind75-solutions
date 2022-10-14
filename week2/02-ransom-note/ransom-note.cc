class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int char_count[128] = {0};
        for (char ch : magazine) {
            char_count[ch]++;
        }
        for (char ch : ransomNote) {
            if (char_count[ch] == 0) {
                return false;
            }
            char_count[ch]--;
        }
        return true;
    }
};