export function removeExtension(str) {
    let index = str.lastIndexOf('.');
    if (index < 0) return str;
    return str.slice(0, index);
}