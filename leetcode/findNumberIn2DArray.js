/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for(let a of matrix){
        for(let b of a) {
            if(b === target) return true;
        }
    }
    return false;
};
