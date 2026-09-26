class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);
        int k = s1.size();
        // Build frequencies
        for (int i = 0; i < k; i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        if (s1Freq == s2Freq)
            return true;

        // Sliding window
        for (int right = k; right < s2.size(); right++) {
            s2Freq[s2[right] - 'a']++;             // add new char
            s2Freq[s2[right - k] - 'a']--;         // remove old char
            if (s1Freq == s2Freq)
                return true;
        }
        return false;
    }
};