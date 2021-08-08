/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    const pre = s.slice(n);
    const last = s.slice(0, n);
    return pre + last;
};
