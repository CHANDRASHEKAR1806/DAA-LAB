def coin_c(N, coins):
    if N == 0:
        return 1
    if N < 0:
        return 0
    if not coins:
        return 0
    m = len(coins)

    dp = [[0] * (N + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        dp[i][0] = 1

    for i in range(1, m + 1):
        for j in range(1, N + 1):


            if j < coins[i - 1]:
                dp[i][j] = dp[i - 1][j]

            else:
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]

    return dp[m][N]
coins = list(map(int, input("Enter coins: ").split()))
N = int(input("Enter amount: "))
print("Number of ways:", coin_c(N, coins))
