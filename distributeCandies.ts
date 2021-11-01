function distributeCandies(candyType: number[]): number {
    const n = candyType.length;
    const eatCount = n / 2;
    let mySet = new Set(candyType);
    const typeCount = mySet.size;

    return typeCount > eatCount ? eatCount : typeCount;
};
