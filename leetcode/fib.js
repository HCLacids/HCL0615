/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    //递归
    // function f(n,a=1,b=1){
    //         if(n<=1)return n;
    //         if(n==2)return b ;
    //         return f(n-1,b,(a+b) % 1000000007);
    //     }
    //     return f(n);
    //动态规划
    // let dp = [0,1];
    // function f(n){
    //     if(dp[n] != undefined){
    //         return dp[n];
    //     } else {
    //         dp[n] = f(n - 1) + f (n - 2);
    //         return  dp[n] % 1000000007
    //     }
    // }
    // return f(n);
    if ( n <= 1) return n;
    let a = b = 1, c = 0;
    while(n-- > 0){
        a = b;
        b = c;
        c = (a + b) % 1000000007;
    }
    return c;
};
