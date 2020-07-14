export function findMax(arr) {
    let max = -Infinity;
    for (let num of arr)
        if (num > max) max = num;
    return max;
}