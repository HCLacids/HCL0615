function minSubArrayLen(k, arr) {
    let l = 0;
    let sum = 0;
    let minWidth = Infinity;
    for(let r = 0; r < arr.length; r++) {
        sum += arr[r];
        while( l < r && sum >= k) {
            minWidth = Math.min(minWidth, r - l + 1);
            sum -= arr[l++];
        }
    }

    return minWidth == Infinity ? 0 : minWidth;
}

console.log(minSubArrayLen(7,[5,1,4,3]))
