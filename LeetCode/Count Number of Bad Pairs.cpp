class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        int n= nums.size();
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < n; pos++) {
            int diff = pos - nums[pos];
            int goodPairsCount = diffCount[diff];
            badPairs += pos - goodPairsCount;
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};
