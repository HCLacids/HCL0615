export function convertToNumbers(params) {
    return params.flatMap(
        (value) => {
            const num = Number(value);
            if (Number.isNaN(num)) {
                return []; // exclude
            } else {
                return [num]; // include
            }
        }
    );
}