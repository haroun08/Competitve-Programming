public class Solution {
    public long MostPoints(int[][] questions) {
        int n = questions.Length;
        long[] mem = new long[n];
        Array.Fill(mem, -1);
        return FindMaxPoints(questions, 0, mem);
    }
    
    private long FindMaxPoints(int[][] questions, int pos, long[] mem) {
        if (pos >= questions.Length) {
            return 0;
        }
        if (mem[pos] != -1) {
            return mem[pos];
        }
        long exclude = FindMaxPoints(questions, pos + 1, mem);
        int skip = questions[pos][1];
        long include = questions[pos][0] + FindMaxPoints(questions, pos + skip + 1, mem);
        mem[pos] = Math.Max(exclude, include);
        return mem[pos];
    }
}
