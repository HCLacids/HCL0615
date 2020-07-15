export function concatStringArray(arr) {
    let str = '';
    for (let a of arr) {
        str += a;
    }
    return str;
}