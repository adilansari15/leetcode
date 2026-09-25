class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }
        int maxCount = count;
        for (int j = k; j < s.size(); j++) {
            if (isVowel(s[j - k])) {
                count--;
            }
            if (isVowel(s[j])) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};