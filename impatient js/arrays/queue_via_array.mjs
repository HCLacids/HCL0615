export class Queue {
    constructor() {
        this.array = [];
    }
    get length() {
        return this.array.length
    }
    enq(str) {
        this.array.push(str)
    }
    deq() {
        if (this.array.length) {
            return this.array.shift();
        } else {
            throw new Error('Queue is empty');
        }
    }

}