export function omitProperties(obj, ...agr) {
    const filteredEntries = Object.entries(obj)
        .filter(entry => !agr.includes(entry[0]));
    return Object.fromEntries(filteredEntries);
}