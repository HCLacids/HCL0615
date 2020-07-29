export function map(arr, sort) {
    return arr.reduce(
        (result, elem, index) => {
            result.push(sort(elem, index, arr));
            return result; // important!
        }, []
    )
}