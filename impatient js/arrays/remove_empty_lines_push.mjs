export function removeEmptyLines(array) {
    let result = []
    for (let arr of array) {
        if (arr)
            result.push(arr);
    }
    return result;
}