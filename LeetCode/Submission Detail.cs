public class Solution {
    public int NumEquivDominoPairs(int[][] dominoes) {
        int[] count = new int[100];
        int result = 0;

        foreach(var domino in dominoes){
            int a = domino[0],b = domino[1];
            int key = a <= b ? a * 10 + b : b * 10 + a;
            result += count[key];  
            count[key]++;
        }
        return result;
    }
}
