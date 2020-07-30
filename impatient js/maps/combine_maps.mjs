export function combineMaps(map1, map2) {
    const arr1 = [...map1];
    const arr2 = [...map2];
    return new Map([...arr1, ...arr2]);
}