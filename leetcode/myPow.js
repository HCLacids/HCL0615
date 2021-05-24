/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n == 0){
        return 1;
    }else if(n < 0){
        return 1 / (x * myPow(x, - n - 1));
    }else if(n % 2 == 1){
        return x * myPow(x, n - 1);
    }else{
        return myPow(x * x, n / 2);
    }
};
