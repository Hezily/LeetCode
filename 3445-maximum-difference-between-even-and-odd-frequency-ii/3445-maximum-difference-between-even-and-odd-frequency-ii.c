
void precomputePrefixSum(int* prefixSumA, int* prefixSumB, const char* s, int n, int a, int b) {
    prefixSumA[0] = 0;
    prefixSumB[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' == a) prefixSumA[i + 1] = 1 + prefixSumA[i];
        else prefixSumA[i + 1] = prefixSumA[i];

        if (s[i] - '0' == b) prefixSumB[i + 1] = 1 + prefixSumB[i];
        else prefixSumB[i + 1] = prefixSumB[i];
    }
}

int calculateDifference(const char* s, int k, int a, int b) {
    int n = strlen(s);
    int* prefixSumA = (int*)malloc((n + 1) * sizeof(int));
    int* prefixSumB = (int*)malloc((n + 1) * sizeof(int));

    precomputePrefixSum(prefixSumA, prefixSumB, s, n, a, b);

    int minVal[4];
    int minIdx[4];
    for (int i = 0; i < 4; ++i) {
        minVal[i] = INT_MAX;
        minIdx[i] = -1;
    }

    minVal[0] = 0;
    minIdx[0] = 0;

    int maxDiff = INT_MIN;

    for (int end = k; end <= n; ++end) {
        int parityA = prefixSumA[end] & 1;
        int parityB = prefixSumB[end] & 1;
        int parity = ((parityA ^ 1) << 1) + parityB;

        if (minVal[parity] != INT_MAX) {
            if (prefixSumB[minIdx[parity]] != prefixSumB[end]) {
                int currDiff = (prefixSumA[end] - prefixSumB[end]) - minVal[parity];
                if (currDiff > maxDiff) maxDiff = currDiff;
            }
        }

        int start = end - k + 1;
        parityA = prefixSumA[start] & 1;
        parityB = prefixSumB[start] & 1;
        parity = (parityA << 1) + parityB;
        int startDiff = prefixSumA[start] - prefixSumB[start];

        if (startDiff < minVal[parity]) {
            minVal[parity] = startDiff;
            minIdx[parity] = start;
        }
    }

    free(prefixSumA);
    free(prefixSumB);

    return maxDiff;
}

int maxDifference(char* s, int k) {
    int maxDiff = INT_MIN;
    for (int a = 0; a <= 4; ++a) {
        for (int b = 0; b <= 4; ++b) {
            if (a == b) continue;
            int diff = calculateDifference(s, k, a, b);
            if (diff > maxDiff) maxDiff = diff;
        }
    }
    return maxDiff;
}
