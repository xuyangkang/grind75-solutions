class Solution {
private:
    string cleanse(const string &s) {
        string new_s;
        for (char ch : s) {
            if (isalnum(ch)) {
                new_s.push_back(tolower(ch));
            }
        }
        return new_s;
    }
public:
    bool isPalindrome(string s) {
        s = cleanse(s);
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
