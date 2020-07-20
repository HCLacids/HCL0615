export function arrayToString(string) {
    let str = '';
    for (const [index, elem] of string.entries()) {
        if (index > 0) {
            str += '\n';
        }
        str += `${index + 1}. ${elem}`
    }
    return str;
}