class Solution {
public:
    int maxScore(string s) {
        int result = 0;
        for (int i = 1; i < s.length(); i++) { 
            int left = count(s.begin(), s.begin() + i, '0');
            int right = count(s.begin()+i,s.end(),'1');
            result = max(result,left+ right);
        }
        return result;

    }
};
