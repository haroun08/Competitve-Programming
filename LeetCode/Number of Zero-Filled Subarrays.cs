public class Solution {
    public long ZeroFilledSubarray(int[] nums) {
        long result = 0, streak = 0;
        foreach (int num in nums) {
            if (num == 0) {
                streak++;
                result += streak;
            } else {
                streak = 0;
            }
        }
        return result;
    }
}
