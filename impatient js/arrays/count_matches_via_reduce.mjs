export function countMatches(arr) {
    return arr.reduce((state, elem) => pred(elem) ? state + 1 : state, 0);
}