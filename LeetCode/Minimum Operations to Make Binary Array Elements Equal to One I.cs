public class Solution {
    public int MinOperations(int[] nums) {
        int result = 0;
        for (int i = 2; i < nums.Length; i++) {
            if (nums[i - 2] == 0) {
                result++;
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        foreach(int num in nums){
            if(num == 0) {
                return -1;
            }
        }
        return  result ;
    
    }
}
