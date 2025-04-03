public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        if (n < 3) return 0;
        
        int[] rightMax = new int[n];
        rightMax[n - 1] = 0;
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = Math.Max(rightMax[j + 1], nums[j + 1]);
        }
        
        long res = 0;
        int leftMax = nums[0];
        for (int j = 1; j < n - 1; j++) {
            long current = (long)(leftMax - nums[j]) * rightMax[j];
            if (current > res) {
                res = current;
            }
            if (nums[j] > leftMax) {
                leftMax = nums[j];
            }
        }
        
        return res;
    }
}
