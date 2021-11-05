function longestSubsequence(arr: number[], difference: number): number {
    let ans = 0;
    let map = new Map();
    for(let a of arr){
        map.set(a, (map.get(a - difference) || 0) + 1);
        ans = Math.max(ans, map.get(a));
    }
    return ans;
};
