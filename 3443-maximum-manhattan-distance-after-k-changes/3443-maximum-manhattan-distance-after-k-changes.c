int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxDistance(char* s, int k) {
    int maxMD = 0;
    int east = 0, west = 0, north = 0, south = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'E') east++;
        else if(s[i] == 'W') west++;
        else if(s[i] == 'N') north++;
        else if(s[i] == 'S') south++;

        int currMD = abs(east - west) + abs(north - south);
        int steps = i + 1;
        int wasted = steps - currMD;

        int extra = 0;
        if(wasted != 0) {
            extra = min(2 * k, wasted);
        }

        int finalCurrentMD = currMD + extra;
        maxMD = max(maxMD, finalCurrentMD);
    }

    return maxMD;
}
