/* npm t exercises/arrays/number_lines_test.mjs
Instructions:
– Create number_lines.mjs so that this test passes
– Use the Array method .map() to do so
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {numberLines} from './number_lines.mjs';

test('numberLines', t => {
    const lines = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'];
    const numbered = ['01: a', '02: b', '03: c', '04: d', '05: e', '06: f', '07: g', '08: h', '09: i', '10: j'];
    assert.deepEqual(numberLines(lines), numbered);
});
