export function replaceObjects(arrayWithObjects) {
    return arrayWithObjects.flatMap(
        ({
            value,
            repeat
        }) => {
            const result = [];
            for (let i = 0; i < repeat; i++) {
                result.push(value);
            }
            return result;
        });
}