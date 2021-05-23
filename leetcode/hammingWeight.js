/**
 * @param {number} n - a positive integer
 * @return {number}
 */
// var hammingWeight = function(n) {
//     let r = n.toString(2).match(/1/g);
//     return r ? r.length : 0;
// };
// var hammingWeight = function(n) {
//    let count = 0;
//     while (n) {
//         count++;
//         n &= n - 1;
//     }
//     return count;
// }

var hammingWeight = function(n) {
    let res = 0;
    while(n) {
        res += n & 1;
        n >>>= 1;
    }
    return res
};
