int maxDifference(char* s) {
    int freq[26] = {0};

    // Step 1: Count the frequency of each character
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }

    int max_odd = -1;
    int min_even = INT_MAX;

    // Step 2: Find max odd frequency and min even frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;

        if (freq[i] % 2 == 1) {  // Odd frequency
            if (freq[i] > max_odd)
                max_odd = freq[i];
        } else {  // Even frequency
            if (freq[i] < min_even)
                min_even = freq[i];
        }
    }

    // Step 3: Return the maximum difference
    return max_odd - min_even;
}
