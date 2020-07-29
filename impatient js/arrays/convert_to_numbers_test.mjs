/* npm t exercises/arrays/convert_to_numbers_test.mjs
Instructions:
– Implement convert_to_numbers.mjs so that the test passes.
– Use Array.prototype.flatMap() to do so.
– Use Number() to convert arbitrary values to numbers.
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {convertToNumbers} from './convert_to_numbers.mjs';

test('convertToNumbers', t => {
  assert.deepEqual(
    convertToNumbers([
      '', // 0 (include)
      '1',
      '2',
      'abc', // NaN (exclude)
      '3',
    ]),
    [0, 1, 2, 3]
  );
  assert.deepEqual(
    convertToNumbers([
      4,
      5,
      NaN, // exclude
      6,
      NaN, // exclude
      7,
    ]),
    [4, 5, 6, 7]
  );
  assert.deepEqual(
    convertToNumbers([
      false, // 0
      true, // 1
      null, // 0
      undefined, // NaN (exclude)
    ]),
    [0, 1, 0]
  );
});
