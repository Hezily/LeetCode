
typedef long long ll;

ll combinations(ll n) {
    if (n < 0)
        return 0;
    return (ll)(n + 1) * (n + 2) / 2;
}

ll distributeCandies(int n, int limit) {
    ll all_combinations = combinations(n);
    ll one_above_limit_combinations = 3LL * combinations(n - (limit + 1));
    ll two_above_limit_combinations = 3LL * combinations(n - 2 * (limit + 1));
    ll three_above_limit_combinations = combinations(n - 3 * (limit + 1));

    ll invalid_combinations = one_above_limit_combinations -
                              two_above_limit_combinations +
                              three_above_limit_combinations;

    ll valid_combinations = all_combinations - invalid_combinations;
    return valid_combinations;
}

