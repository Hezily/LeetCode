
typedef long long ll;

int countSteps(int n, ll prefix1, ll prefix2) {
    int steps = 0;
    while (prefix1 <= n) {
        steps += (int)( (prefix2 <= (ll)n + 1 ? prefix2 : (ll)n + 1) - prefix1 );
        prefix1 *= 10;
        prefix2 *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    int curr = 1;
    k -= 1;

    while (k > 0) {
        int steps = countSteps(n, curr, curr + 1);
        if (steps <= k) {
            curr++;
            k -= steps;
        } else {
            curr *= 10;
            k -= 1;
        }
    }

    return curr;
}
