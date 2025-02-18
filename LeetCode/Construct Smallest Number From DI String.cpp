class Solution {
public:
    bool check(string &sequence, string &pattern) {
        int n = pattern.size();
        for (int i = 0; i < n;i++) {
            if (pattern[i] == 'I') {
                if (sequence[i] > sequence[i + 1])
                    return false;
            } else {
                if (sequence[i] < sequence[i + 1])
                    return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        string sequence = "";

        for (int num = 1; num <= 1 + n; num++) {
            sequence.push_back(num + '0');
        }

        string permutation = sequence;

        while (!check(permutation, pattern)) {
            next_permutation(permutation.begin(), permutation.end());
        }

        return permutation;
    }
};
