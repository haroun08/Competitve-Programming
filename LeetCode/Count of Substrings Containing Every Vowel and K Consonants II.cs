public class Solution {
    public long CountOfSubstrings(string word, int k) {
        return AtLeastK(word, k) - AtLeastK(word, k + 1);
    }

    private long AtLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        Dictionary<char, int> vowelCount = new Dictionary<char, int>();
        int consonantCount = 0;

        while (end < word.Length) {
            char newLetter = word[end];

            if (IsVowel(newLetter)) {
                if (vowelCount.ContainsKey(newLetter)) {
                    vowelCount[newLetter]++;
                } else {
                    vowelCount[newLetter] = 1;
                }
            } else {
                consonantCount++;
            }

             while (vowelCount.Count == 5 && consonantCount >= k) {
                 numValidSubstrings += word.Length - end;

                char startLetter = word[start];
                if (IsVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.Remove(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }

    private static bool IsVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
