class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(nums.begin(),nums.end());
        int right = 0,result = 0,n = nums.size();

        for(int left = 0; left < n;left++){
            while(right < n && nums[right] - nums[left] <= 2* k){
                right++;
            }
            result = max(result,right - left);
        }
        return result;

    }
};
