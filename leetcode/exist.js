/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
let dfs = (board, word, row, col, k) => {
     if(row >= board.length || row < 0 || col >= board[0].length || col < 0 || board[row][col] != word[k]) return false;
    if(k == word.length - 1) return true;
    board[row][col] = '\0';
    let res = dfs(board, word, row + 1, col, k + 1) || dfs(board, word, row, col + 1, k + 1) || dfs(board, word ,row - 1, col, k + 1) || dfs(board, word, row, col - 1, k + 1);
    board[row][col] = word[k];
    return res;
}
var exist = function(board, word) {
   for(let row = 0; row < board.length; row++){
       for(let col = 0; col < board[row].length; col++){
           if(dfs(board, word ,row ,col, 0)) return true;
       }
   }
   return false;  
};
