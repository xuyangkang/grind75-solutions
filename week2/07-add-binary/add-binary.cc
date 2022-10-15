class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int len = max(a.length(), b.length());
        string ans;
        for (int i = 0; i < len; i++) {
            int ai = i < a.size() ? (a[i] - '0') : 0;
            int bi = i < b.size() ? (b[i] - '0') : 0;
            int val = ai + bi + carry;
            ans.push_back('0' + val % 2);
            carry = val >= 2 ? 1 : 0;
        }
        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};