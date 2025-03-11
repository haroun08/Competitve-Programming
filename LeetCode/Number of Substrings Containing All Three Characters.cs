using System;

public class Solution {
    public int NumberOfSubstrings(string s) {
        int len = s.Length;
        int left = 0, right = 0;
        int[] freq = new int[3];
        int total = 0;

        while (right < len) {
            char curr = s[right];
            freq[curr - 'a']++;

            while (HasAllChars(freq)) {
                total += len - right;
                
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }

            right++;
        }

        return total;
    }

    private bool HasAllChars(int[] freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
}
