### Fibonacci (pure recursion)
def fibo(n):
    if n == 0:  return 0
    if n == 1:  return 1

    return fibo(n-1) + fibo(n-2)

### Fibonacci (Memoized-TopDown)
memo = {}
def fibo_memo(n):
    if not n:   return 0
    if n == 1:  return 1

    if n in memo:
        return memo[n]

    memo[n] = fibo_memo(n-1) + fibo_memo(n-2)
    return memo[n]

### Fibonacci DP (BottomUp)
def fibo_dp(n):
    if n <= 1:
        return n

    dp = [0] * (n+1)
    dp[0], dp[1] = 0, 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[-1]


### Factorial (pure recursion)
def fact(n):
    if n <= 1:
        return 1

    return n * fact(n-1)

### Factorial (Memoized-TopDown)
memo = {}
def fact_memo(n):
    if n <= 1:
        return 1

    if n in memo:   return memo[n]
    memo[n] = n * fact_memo(n-1)
    return memo[n]

### Factorial DP (BottomUp)
def fact_dp(n):
    if n <= 1:
        return 1

    dp = [0] * (n+1)
    dp[0] = dp[1] = 1
    for i in range(2, n+1):
        dp[i] = i * dp[i-1]

    return dp[-1]

### 0-1 KnapSack problem (pure recursion)
def knapsack(weight, profit, capacity, n):
    if not n or not capacity:
        return 0

    if weight[n-1] <= capacity:
        return max(profit[n-1] + knapsack(weight, profit, capacity - weight[n-1], n-1),
                              knapsack(weight, profit, capacity, n-1))
    return knapsack(weight, profit, capacity, n-1)

### 0-1 KnapSack problem (Memoized-TopDown)
memo = {}
def knapsack_memoized(weight, profit, capacity, n):
    if not n or not capacity:
        return 0

    key = (capacity, n)
    if key in memo:
        return memo[key]

    if weight[n-1] <= capacity:
        memo[key] = max(profit[n-1] + knapsack(weight, profit, capacity - weight[n-1], n-1),
                                  knapsack(weight, profit, capacity, n-1))
    else:
        memo[key] = knapsack(weight, profit, capacity, n-1)

    return memo[key]

### 0-1 Knapsack DP (BottomUp)
def knapsack_dp(weight, profit, capacity, n):
    if capacity == 0 or n == 0:
        return 0

    dp = [[0] * (capacity+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(capacity+1):
            if weight[i-1] <= j:
                dp[i][j] = max(profit[i-1] + dp[i-1][j - weight[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]

    return dp[-1][-1]


### Subset Sum (pure recursion)
def subset_sum(arr, target, n):
    if target == 0:
        return True
    if n == 0:
        return False

    if arr[n-1] > target:
        return subset_sum(arr, target, n-1)

    return subset_sum(arr, target-arr[n-1], n-1) or subset_sum(arr, target, n-1)

### Subset sum (Memoized-TopDown)
memo = {}
def subset_sum_memo(arr, target, n):
    if target == 0:
        return True
    if n == 0:
        return False

    key = (n, target)
    if key in memo:
        return memo[key]

    if arr[n-1] > target:
        memo[key] = subset_sum(arr, target, n-1)
    else:
        memo[key] = subset_sum(arr, target-arr[n-1], n-1) or subset_sum(arr, target, n-1)

    return memo[key]

### Subset Sum DP (BottomUp)
def subset_sum_dp(arr, target, n):
    if n == 0:
        return False
    if target == 0:
        return True

    dp = [[False] * (target+1) for _ in range(n+1)]
    dp[0][0] = True
    for i in range(1, n+1):
        for j in range(1, target+1):
            if arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j]

    return dp[-1][-1]

### Equal sum subsets (pure recursion)
def equal_sum_subset(arr, n):
    arr_sum = sum(arr)
    if arr_sum & 1:
        return False

    target = arr_sum // 2
    def solve(arr, sum_, n):
        if sum_ == 0:
            return True
        if n == 0:
            return False

        if arr[n-1] > sum_:
            return solve(arr, sum_, n-1)

        return solve(arr, sum_ - arr[n-1], n-1) or solve(arr, sum_, n-1)

    return solve(arr, target, n)

### Equal sum subset (Memoized-TopDown)
def equal_sum_subset_memo(arr, n):
    arr_sum = sum(arr)
    if arr_sum & 1:
        return False

    memo = {}
    def solve(arr, target, n):
        if n == 0:
            return False
        if target == 0:
            return True

        key = (target, n)
        if key in memo:
            return memo[key]

        if arr[n-1] > target:
            memo[key] = solve(arr, target, n-1)
        else:
            memo[key] = solve(arr, target-arr[n-1], n-1) or solve(arr, target, n-1)
        return memo[key]

    return solve(arr, arr_sum//2, n)

### Equal sum subsets DP (BottomUp)
def equal_sum_subset_dp(arr):
    arr_sum = sum(arr)
    if arr_sum & 1:
        return False

    target = arr_sum // 2
    dp = [[False] * (target+1) for _ in range(len(arr)+1)]
    dp[0][0] = True

    for i in range(1, len(arr)+1):
        for j in range(1, target+1):
            if arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j - arr[i-1]]

    return dp[-1][-1]


### Count subsets with sum (pure recursion)
def count_subsets(arr, sum_, n):
    if sum_ == 0:
        return 1
    if n == 0:
        return 0

    if arr[n-1] > sum_:
        return count_subsets(arr, sum_, n-1)
    else:
        return count_subsets(arr, sum_ - arr[n-1], n-1) + count_subsets(arr, sum_, n-1)

### Count subsets with sum (Memoized-TopDown)
def count_subsets_memo(arr, sum_, n):
    memo = {}
    def solve(sum_, n):
        if sum_ == 0:
            return 1
        if n == 0:
            return 0

        key = (sum_, n)
        if key in memo:
            return memo[key]

        if arr[n-1] > sum_:
            memo[key] = solve(sum_, n-1)
        else:
            memo[key] = solve(sum_ - arr[n-1], n-1) + solve(sum_, n-1)

        return memo[key]

    return solve(sum_, n)

### Count subsets with sum DP (BottomUp)
def count_subsets_dp(arr, sum_, n):
    if sum_ == 0:
        return 1
    if n == 0:
        return 0

    dp = [[0]*(sum_+1) for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, sum_+1):
            if arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]

    return dp[-1][-1]


### Minimum difference subset sum (pure-recursion)
def min_diff_subset_sum(arr, n, total, calculated_sum):
    if n == 0:
        return abs((total - calculated_sum) - calculated_sum)

    return min(min_diff_subset_sum(arr, n-1, total, calculated_sum + arr[n-1]),
                min_diff_subset_sum(arr, n-1, total, calculated_sum))

### Minimum difference subset sum (Memoized-TopDown)
def min_diff_subset_sum_memo(arr, n, total, calculated_sum):
    memo = {}
    def solve(n, calculated_sum):
        if n == 0:
            return abs((total - calculated_sum) - calculated_sum)

        key = (calculated_sum, n)
        if key in memo:
            return memo[key]

        memo[key] = min(solve(n-1, calculated_sum), solve(n-1, calculated_sum + arr[n-1]))
        return memo[key]

    return solve(n, calculated_sum)

### Minimum difference subset sum DP (BottomUp)
def min_diff_subset_sum_dp(arr, n, total, calculated_sum):
    ## Todo
    pass


### Number of subset with given difference (pure recursion)
def subset_given_diff(arr, n, X):
    if X == 0:
        return 1
    if n == 0:
        return 0

    if arr[n-1] > X:
        return subset_given_diff(arr, n-1, X)
    return subset_given_diff(arr, n-1, X) + subset_given_diff(arr, n-1, X - arr[n-1])


### Number of subset with given difference (Memozied-TopDown)
def subset_given_diff_memo(arr, n, X):
    memo = {}
    def solve(sum_, n):
        if X == 0:
            return 1
        if n == 0:
            return 0

        key = (sum_, n)
        if key in memo:
            return memo[key]

        if arr[n-1] > X:
            memo[key] = subset_given_diff(arr, n-1, X)
        else:
            memo[key] = subset_given_diff(arr, n-1, X) + subset_given_diff(arr, n-1, X - arr[n-1])

        return memo[key]

    return solve(X, n)
print(subset_given_diff_memo(arr, 4, target_sum))

### Number of subset with given difference DP (BottomUp)
def subset_given_diff_dp(arr, n, X):
    if n == 0:
        return 0

    dp = [[0] * (X+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, X+1):
            if dp[i-1][j] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]]

    return dp[-1][-1]

print(subset_given_diff_dp([1,1,1,1,1], 5, 4))


### Target sum (pure recursion)
def target_sum(arr, n, sum_):
    if sum_ == 0:
        return 1
    if n == 0:
        return 0

    if arr[n-1] > sum_:
        return target_sum(arr, n-1, sum_)

    return target_sum(arr, n-1, sum_ - arr[n-1]) + target_sum(arr, n-1, sum_)


### Unbounded KnapSack problem
def unbounded_knapsack(weight, profit, capacity, n):
    if not n or not capacity:
        return 0

    dp = [[0]*(capacity+1) for _ in range(n+1)]
    dp[0][0] = 0
    for i in range(1, n+1):
        for j in range(1, capacity+1):
            if weight[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(profit[i-1] + dp[i][j-weight[i-1]], dp[i-1][j])

    return dp[-1][-1]

### Rod Cutting (pure recursion) [Variation of Unbounded Knapsack]
def rod_cut(pieces, n, profit):
    if not n or not pieces:
        return 0

    dp = [[0] * (n+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(n+1):
            if pieces[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i][j-pieces[i-1]])

    return dp[-1][-1]

### Coin change (Number of ways)
def coin_change(coins, target, n):
    if not coins or not target:
        return 0

    dp = [[0]*(target+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, target+1):
            if coins[i-1] > target:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]

    return dp[-1][-1]

### LCS (pure recursion)
def lcs(s1, s2, n, m):
    if n < 0 or m < 0:
        return 0

    if s1[n-1] == s2[m-1]:
        return 1 + lcs(s1, s2, n-1, m-1)

    return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1))


### LCS (Memoization Top-Down)
memo = {}
def lcs_memo(s1, s2, n, m):
    if n < 0 or m < 0:
        return 0

    key = (n, m)
    if key in memo:
        return memo[key]

    if s1[n-1] == s2[m-1]:
        memo[key] = 1 + lcs(s1, s2, n-1, m-1)
    else:
        memo[key] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1))
    return memo[key]


### LCS (DP BottomUp)
def lcs_dp(s1, s2):
    if not s1 or not s2:
        return 0

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[-1][-1]

### Longest Common Substring (pure recursion)
def lcsubs(s1, s2, n, m, res=0):
    if n < 0 or m < 0:
        return res

    if s1[n-1] == s2[m-1]:
        return lcsubs(s1, s2, n-1, m-1, res+1)

    return max(res, lcsubs(s1, s2, n, m-1, 0), lcsubs(s1, s2, n-1, m, 0))

### Longest Common Substring (Memoization TopDown)
memo = {}
def lcsubs_memo(s1, s2, n, m, res=0):
    if n < 0 or m < 0:
        return res

    key = (n, m, res)
    if key in memo:
        return memo[key]

    if s1[n-1] == s2[m-1]:
        memo[key] = lcsubs_memo(s1, s2, n-1, m-1, res+1)
    else:
        memo[key] = max(res, lcsubs_memo(s1, s2, n-1, m, 0), lcsubs_memo(s1, s2, n, m-1, 0))
    return memo[key]

### Longest Common Substring (DP BottomUp)
def lcsubs_dp(s1, s2):
    if not s1 or not s2:
        return 0

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = 0

    return max(max(row) for row in dp)

### Print longest common subsequence
def print_lcs(s1, s2):
    if not s1 or not s2:
        return ""

    # Just get the longest common subsequence length using DP
    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]

    for i in range(1, len(s1)):
        for j in range(1, len(s2)):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    # Traverse from the end of both strings
    res = ""
    i, j = len(s1), len(s2)

    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]: # If equal the append to result and decrement
            res += s1[i-1]
            i -= 1
            j -= 1
        else:
            # If not, then check which one is larger and move in that direction in DP table
            if dp[i-1][j] > dp[i][j-1]: i -= 1
            else:   j -= 1

    return res[::-1] # Since we are traversing from the end we need to reverse the result

### Print shortest/length common supersequence
# a = "ABCDEF", b = "BCF", res = "ABCF"
def shortest_supersequence(s1, s2):
    if not s1 or not s2:
        return 0

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    lcs_len = dp[-1][-1]
    return (len(s1) + len(s2)) - lcs_len


### Another Approach
def shortest_supersequence_recusive(s1, s2, n, m):
    if not n:
        return m
    if not m:
        return n

    if s1[n-1] == s2[m-1]:
        return 1 + shortest_supersequence_recusive(s1, s2, n-1, m-1)

    return 1 + min(shortest_supersequence_recusive(s1, s2, n-1, m),
                    shortest_supersequence_recusive(s1, s2, n, m-1))

### Using DP
def shortest_supersequence_dp(s1, s2):
    if not s1 or not s2:
        return 0

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(len(s1)+1):
        for j in range(len(s2)+1):
            if not i:
                dp[i][j] = j
            elif not j:
                dp[i][j] = i
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])

    return dp[-1][-1]
# print(shortest_supersequence_dp("geek", "eke"))

### Print shortest common supersequence
def print_shortest_supersequence(s1, s2):
    if not s1 or not s2:
        return 0

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(len(s1)+1):
        for j in range(len(s2)+1):
            if not i:
                dp[i][j] = j
            elif not j:
                dp[i][j] = i
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])

    i, j = len(s1), len(s2)
    res = ""
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            res += s1[i-1]
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            res += s2[j-1]
            j -= 1
        else:
            res += s1[i-1]
            i -= 1

    while i > 0:
        res += s1[i-1]
        i -= 1
    while j > 0:
        res += s2[j-1]
        j -= 1

    return res[::-1]
# print(print_shortest_supersequence("AGGTAB", "GXTXAYB"))

### Minimum number of insertions and deletion to convert s1 to s2
def min_insert_del(s1, s2):
    if not s1:
        return len(s2)
    if not s2:
        return len(s1)

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return (len(s1) + len(s2)) - 2 * dp[-1][-1]

### Longest palindromic subsequence
def longest_palindromic_subsq(s, i, j):
    if i == j:
        return 1
    if i > j:
        return 0

    if s[i] == s[j]:
        return 2 + longest_palindromic_subsq(s, i+1, j-1)

    return max(longest_palindromic_subsq(s, i, j-1),
                longest_palindromic_subsq(s, i+1, j))

### Longest palindromic subsequence (Memoized)
memo = {}
def longest_palindromic_subsq_memo(s, i, j):
    if i == j:
        return 1
    if i > j:
        return 0

    key = (i, j)
    if key in memo:
        return memo[key]
    if s[i] == s[j]:
        memo[key] = 2 + longest_palindromic_subsq(s, i+1, j-1)
    else:
        memo[key] = max(longest_palindromic_subsq(s, i, j-1),
                    longest_palindromic_subsq(s, i+1, j))
    return memo[key]

### Longest palindromic subsequence (DP)
### (Approach find the LCS between the string and its reversed)
def longest_palindromic_subsq_dp(s):

    def lps(t):
        dp = [[0] * (len(s)+1) for _ in range(len(s)+1)]
        for i in range(1, len(s)+1):
            for j in range(1, len(s)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[-1][-1]

    return lps(s[::-1])


### Number of deletion required to make string palidnrome
# Approach (Length of string  - Longest palindromic Subsequence length)
def longest_palindromic_subsq_dp(s):

    def lps(t):
        dp = [[0] * (len(s)+1) for _ in range(len(s)+1)]

        for i in range(1, len(s)+1):
            for j in range(1, len(s)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return len(s) - lps(s[::-1])

### Buy and sell stocks with Cooldown
memo = {}
def buy_sell_cooldown(prices, buy, i=0):
    if i >= len(prices):
        return 0

    key = (i, buy)
    if key in memo:
        return memo[key]
    cooldown = buy_sell_cooldown(prices, buy, i+1)
    if buy:
        bought = buy_sell_cooldown(prices, False, i+1) - prices[i]
        memo[key] = max(bought, cooldown)
    else:
        sell = buy_sell_cooldown(prices, True, i+2) + prices[i]
        memo[key] = max(sell, cooldown)

    return memo[key]
print(buy_sell_cooldown([1,2,3,0,2], True))

### Longest repeating subsequence (recursion)
# Approach : Get the LCS of string with itself and dont include characters at same index as
# a single character can belong to just one subsequence. i.e do not repeat characters
def longest_repeating_subsequence(s):
    "AABEBCDD"
    "DDCBEBAA"
    def get_lcs(t, n, m):
        if n <= 0 or m <= 0:
            return 0

        if s[n-1] == t[m-1] and n != m:
            return 1 + get_lcs(t, n-1, m-1)

        return max(get_lcs(t, n-1, m), get_lcs(t, n, m-1))

    return get_lcs(s, len(s), len(s))

print(longest_repeating_subsequence("AABEBCDD"))

### Longest repeating subsequence (Memoization)
def longest_repeating_subsequence_memo(s):
    memo = {}
    def get_lcs(t, n, m):
        if n <= 0 or m <= 0:
            return 0
        key = (n, m)
        if key in memo:
            return memo[key]

        if s[n-1] == t[m-1] and n != m:
            memo[key] =  1 + get_lcs(t, n-1, m-1)
        else:
            memo[key] = max(get_lcs(t, n-1, m), get_lcs(t, n, m-1))
        return memo[key]

    return get_lcs(s, len(s), len(s))

### Longest repeating subsequence (DP)
def longest_repeating_subsequence_dp(s):
    if not s:
        return 0

    dp = [[0] * (len(s)+1) for _ in range(len(s)+1)]
    for i in range(1, len(s)+1):
        for j in range(1, len(s)+1):
            if s[i-1] == s[j-1] and i != j:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[-1][-1]


### Sequeunce pattern matching (Is s1 a subsequence of s2)
# Note: DP O(N^2), But using Two pointers we can achieve O(N)
def sqn_pattern_match_dp(s1, s2):
    if not s1:
        return True
    if not s2:
        return False

    dp = [[0] * (len(s2)+1) for _ in range(len(s1)+1)]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return len(s1) == dp[-1][-1]

print(sqn_pattern_match_dp("AXY", "ADXCPY"))

### Minimum no of deletions/insertions to make string palidrome
### Length of String  - Longest palindromic subseqeunce

def min_del_inserts(s):
    def lps(t):
        dp = [[0] * (len(s)+1) for _ in range(len(s)+1)]

        for i in range(1, len(s)+1):
            for j in range(1, len(s)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[-1][-1]

    return len(s) - lps(s[::-1])

# Matrix Chain Multiplication (Recursive)
def mcm_recursive(arr, i, j):
    if i == j:
        return 0

    ans = float("inf")

    for k in range(i, j):
        ans = min(ans, mcm_recursive(arr, i, k) +
                    mcm_recursive(arr, k+1, j) +
                    (arr[i-1] * arr[k] * arr[j]))

    return ans

print(mcm_recursive([1, 2, 3, 4, 3], 1, 4))

# MCM Memoization
memo = {}
def mcm_memo(arr, i, j):
    if i == j:
        return 0
    key = (i, j)

    if key in memo:
        return memo[key]

    ans = float("inf")
    for k in range(i, j):
        ans = min(ans, mcm_recursive(arr, i, k) +
                    mcm_recursive(arr, k+1, j) +
                    (arr[i-1] * arr[k] * arr[j]))

    memo[key] = ans
    return memo[key]
print(mcm_memo([1, 2, 3, 4, 3], 1, 4))
