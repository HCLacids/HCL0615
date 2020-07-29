/* npm t exercises/arrays/remove_empty_lines_filter_test.mjs
Instructions:
– Create remove_empty_lines_filter.mjs so that this test passes
– You can assume that the parameter is always an Array of strings
– Use Array.prototype.filter
– Similar: remove_empty_lines_push_test.mjs
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {removeEmptyLines} from './remove_empty_lines_filter.mjs';

test('removeEmptyLines() via .filter()', () => {
    assert.deepEqual(
        removeEmptyLines(['', 'a', 'b', '', '', 'c', 'd', '']),
        ['a', 'b', 'c', 'd']);
    assert.deepEqual(
        removeEmptyLines([]),
        []);
    assert.deepEqual(
        removeEmptyLines(['a']),
        ['a']);
    assert.deepEqual(
        removeEmptyLines(['a', 'b']),
        ['a', 'b']);
    assert.deepEqual(
        removeEmptyLines(['']),
        []);
    assert.deepEqual(
        removeEmptyLines(['', 'a', '']),
        ['a']);
});
