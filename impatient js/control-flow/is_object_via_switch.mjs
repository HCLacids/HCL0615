export function isObject(x) {
    return x !== null && (typeof x === 'object' || typeof x === 'function');
    if (x === null) {
        return false;
    } else {
        switch (typeof x) {
            case 'function':
                ;
            case 'object':
                return true;
                break;
            default:
                return false;
        }
    }
}