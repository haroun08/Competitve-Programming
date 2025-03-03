class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> rearranged(n);
        int lessIdx = 0, greaterIdx = n - 1;
        
        for (int forwardIdx = 0, reverseIdx = n - 1; forwardIdx < n; forwardIdx++, reverseIdx--) {
            if (nums[forwardIdx] < pivot) {
                rearranged[lessIdx++] = nums[forwardIdx];
            }
            if (nums[reverseIdx] > pivot) {
                rearranged[greaterIdx--] = nums[reverseIdx];
            }
        }
        
        while (lessIdx <= greaterIdx) {
            rearranged[lessIdx++] = pivot;
        }
        
        return rearranged;
    }
};
