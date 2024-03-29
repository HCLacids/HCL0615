/**
 * @param {number} n
 * @return {number[]}
 */

let weight = (n) => {
    let res = 0;
    while(n){
        n = Math.floor(n / 10)
        res++;
    }
    return res;
}

var printNumbers = function(n) {
    let res = [];
    for(let i = 1; i <= Math.pow(10 ,n) - 1; i++) {
        res.push(i);
    }
    return res;
};
