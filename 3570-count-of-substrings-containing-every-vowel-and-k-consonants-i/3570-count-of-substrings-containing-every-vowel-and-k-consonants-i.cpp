class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int totalSubstrings = 0;

        // Lambda function to check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        // Lambda function to check if a character is a consonant
        auto isConsonant = [](char c) {
            return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
        };

        for (int i = 0; i < n; ++i) {
            // Track the presence of each vowel and the consonant count
            int vowelCount[5] = {0};  // 'a', 'e', 'i', 'o', 'u'
            int consonantCount = 0;

            for (int j = i; j < n; ++j) {
                char c = word[j];

                // Count each vowel individually
                if (c == 'a') vowelCount[0]++;
                else if (c == 'e') vowelCount[1]++;
                else if (c == 'i') vowelCount[2]++;
                else if (c == 'o') vowelCount[3]++;
                else if (c == 'u') vowelCount[4]++;
                else if (isConsonant(c)) consonantCount++;
                if (vowelCount[0] >= 1 && vowelCount[1] >= 1 && vowelCount[2] >= 1 && 
                    vowelCount[3] >= 1 && vowelCount[4] >= 1 && consonantCount == k) {
                    totalSubstrings++;
                }
            }
        }

        return totalSubstrings;
    }
};
