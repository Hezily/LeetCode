int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;

    int* candies = (int*)malloc(sizeof(int) * ratingsSize);
    
    // Step 1: Initialize all candies to 1
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }

    // Step 2: Left to Right pass
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right to Left pass
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    // Step 4: Sum all candies
    int total = 0;
    for (int i = 0; i < ratingsSize; i++) {
        total += candies[i];
    }

    free(candies);
    return total;
}
