/**
 * @param {number[][]} matrix
 * @return {number[]}
 */

let dfs = (matrix, direction, row, col, res, i) => {
    if(i === matrix.length * matrix[0].length) return;
    if(direction === 'right' && (col === matrix[0].length - 1 || Number.isNaN(matrix[row][col + 1]))) direction = change(direction);
    if(direction === 'down' && (row === matrix.length - 1 || Number.isNaN(matrix[row + 1][col]))) direction = change(direction);
    if(direction === 'left' && (col === 0 || Number.isNaN(matrix[row][col - 1]))) direction = change(direction);
    if(direction === 'up' && (row === 0 || Number.isNaN(matrix[row - 1][col]))) direction = change(direction);
    if(row <= matrix.length - 1 && col <= matrix[0].length - 1) {
        res[i++] = matrix[row][col];
        matrix[row][col] = NaN;
        }
    switch(direction) {
        case 'right': dfs(matrix, direction, row, col + 1, res, i); break;
        case 'down': dfs(matrix, direction, row + 1, col, res, i); break;
        case 'left': dfs(matrix, direction,row, col - 1, res, i); break;
        case 'up': dfs(matrix, direction, row - 1, col, res, i); break;
    }
}

let change = (direction) => {
    switch(direction) {
        case 'right': return 'down';
        case 'down': return 'left';
        case 'left': return 'up';
        case 'up': return 'right';
    }
}

var spiralOrder = function(matrix) {
    let res = [];
    if(!matrix.length) return res;
    dfs(matrix, 'right', 0, 0, res, 0);
    return res;
};
