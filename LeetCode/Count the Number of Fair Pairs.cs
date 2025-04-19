public class Solution {
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        return LowerBound(nums, upper + 1) - LowerBound(nums, lower);
    }
    
    private long LowerBound(int[] nums, int value) {
        int left = 0;
        int right = nums.Length - 1;
        long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < value) {
                result += right - left;
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
}
