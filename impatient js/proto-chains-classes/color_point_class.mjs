import { Point } from './point_class.mjs'

export class ColorPoint extends Point {
    constructor(x, y, color) {
        super(x, y);
        this.color = color;
        this.x = x;
        this.y = y;
    }
    toString() {
        return `(${this.x}, ${this.y}) in ${this.color}`
    }
}