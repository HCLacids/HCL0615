/**
 * @param {number} n
 * @return {number}
 */
var numWays = function(n) {
    if (n == 0) return 1;
    let dp = [1, 2];
    if(dp[n - 1]) {
        return dp[n - 1];
    } else {
        for(let a = 3; a <= n; a++) {
                dp[a - 1] = (dp[a - 2] + dp[a - 3]) % 1000000007;
        }
    }
    return dp[n - 1];
};
