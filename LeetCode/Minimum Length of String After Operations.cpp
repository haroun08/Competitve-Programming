class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> freq;

        for(char c: s) {
            freq[c]++;
        }

        int requiredDelet = 0;
        for(auto it = freq.begin();it!=freq.end();it++){
            if(it->second % 2 == 1){
                requiredDelet += it->second -1;
            }
            else {
                requiredDelet += it->second -2;
            }
        }

        return s.length()-requiredDelet;
    }
};
