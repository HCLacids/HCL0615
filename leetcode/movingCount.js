/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
let sum = (num)=>{
    let arr = num.toString().split('');
    return arr.reduce((a,b)=> {return Number(a) + Number(b)}, 0);
}

// let dfs = (visited, m, n, k, row, col) => {
//     if(row >= m || col >= n || k < sum(row) + sum(col) || visited[row][col]) return 0;
//     visited[row][col] = true;
//     return 1 + dfs(visited, m, n, k, row + 1, col) + dfs(visited, m, n, k, row, col + 1);
// }

// var movingCount = function(m, n, k ) {
//     if(k === 0) return 1;
//     let visited = new Array();
//     for(let a  = 0; a < m; a++){
//         visited[a] = new Array();
//         for(let b = 0; b < n; b++){
//             visited[a][b]= false;
//         }
//     }
//     return dfs(visited, m, n, k, 0, 0);
// };

var movingCount = function(m, n, k) {
    let res = 0;
    if(k === 0) return 1;
    let visited = new Array();
    for(let a  = 0; a < m; a++){
        visited[a] = new Array();
        for(let b = 0; b < n; b++){
            visited[a][b]= false;
        }
    }
    let queue = [{row: 0, col: 0}];
    while(queue.length) {
        let {row, col} = queue.shift();
        if(row >= m || col >= n || k < sum(row) + sum(col) || visited[row][col]) continue;
        visited[row][col] = true;
        res += 1;
        queue.push({row: row + 1, col});
        queue.push({row, col: col + 1});
    }
    return res;
}
