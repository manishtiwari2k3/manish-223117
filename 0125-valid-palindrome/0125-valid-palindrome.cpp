class Solution {
public:
    bool isPalindrome(string s) {
        string rev, filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered.push_back(tolower(c));
            }
        }

        rev = filtered;
        reverse(rev.begin(), rev.end());

        return filtered == rev;
    }
};



