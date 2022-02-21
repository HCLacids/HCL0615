function divide(dividend, divisor) {
    let negative = 2;
    if (dividend > 0) {
        negative--;
        dividend = -dividend;
    }
    if(divisor > 0) {
        negative--;
        divisor = -divisor;
    }

    let result = divideCore(dividend, divisor);
    return negative == 1 ? -result : result;
}

function divideCore(dividend, divisor) {
    let res = 0;
    while (dividend <= divisor) {
        let value = divisor;
        let quotient = 1;
        while (dividend <= value + value) {
            quotient += quotient;
            value += value;
        }
        res += quotient;
        dividend -= value;
    }
    return res;
}

console.log(divide(15,2));
