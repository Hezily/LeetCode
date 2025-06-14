int remap(int num, char from, char to) {
    char str[20];
    sprintf(str, "%d", num);
    
    for (int i = 0; str[i]; i++) {
        if (str[i] == from) {
            str[i] = to;
        }
    }

    return atoi(str);
}

int minMaxDifference(int num) {
    char str[20];
    sprintf(str, "%d", num);
    
    int maxVal = num;
    int minVal = num;

    // Try all digits 0-9 as 'from' and all digits 0-9 as 'to'
    for (char d = '0'; d <= '9'; d++) {
        for (char r = '0'; r <= '9'; r++) {
            if (d == r) continue;

            int newNum = remap(num, d, r);
            if (newNum > maxVal) maxVal = newNum;
            if (newNum < minVal) minVal = newNum;
        }
    }

    return maxVal - minVal;
}
