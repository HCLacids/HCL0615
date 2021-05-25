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
    for(let i = 1; weight(i) <= n; i++) {
        res.push(i);
    }
    return res;
};
