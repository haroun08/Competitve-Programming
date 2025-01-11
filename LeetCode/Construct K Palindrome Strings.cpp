class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n<k) {
            return false;
        }
        if(n==k) {
            return true;
        }
        unordered_map<char,int> freq;
        for(char c : s) {
            freq[c]++;
        }
        int nbOdd=0;
        for(auto it = freq.begin();it!=freq.end();it++){
            if(it->second % 2 ==1){
                nbOdd++;
            }
        }
        return (nbOdd <= k);
    }
};
