/**
 * @param {number} n
 * @return {number}
 */
var cuttingRope = function(n) {
    if(n <= 3) return n - 1;
        let a = Math.floor(n / 3), b = n % 3;
        if(b == 0) return Math.pow(3, a);
        if(b == 1) return Math.pow(3, a - 1) * 4;
        return Math.pow(3, a) * 2;
};
