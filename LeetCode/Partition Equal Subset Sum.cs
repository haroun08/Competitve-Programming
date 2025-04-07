public class Solution {
    public bool CanPartition(int[] nums) {
        int totalSum = 0;
        foreach (int num in nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        bool[] dp = new bool[target + 1];
        dp[0] = true;
        
        foreach (int num in nums) {
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[target];
    }
}
