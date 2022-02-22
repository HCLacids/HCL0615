function addBinary(a,b) {
    let res = '';
    const aLen = a.length - 1;
    const bLen = b.length - 1;
    let aPoint = aLen;
    let bPoint = bLen;
    let n = 0;

    while(aPoint >= 0 || bPoint >= 0) {
        let aN = aPoint >= 0 ? Number(a[aPoint--]) : 0;
        let bN = bPoint >= 0 ? Number(b[bPoint--]) : 0;

        let sum = aN + bN + n;
        n = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum - 2 : sum; 
        res = String(sum) + res;
    }
    if(n) {
        res = '1' + res;
    }
    return res;
}

console.log(addBinary('11','10'));
