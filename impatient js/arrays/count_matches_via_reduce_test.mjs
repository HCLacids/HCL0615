/* npm t exercises/arrays/count_matches_via_reduce_test.mjs
Instructions:
- Use Array.prototype.reduce() to implement count_matches_via_reduce.mjs
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {countMatches} from './count_matches_via_reduce.mjs';

test('countMatches() via .reduce()', () => {
  assert.equal(
    countMatches([1, 2, 3], x => x < 0),
    0);
  assert.equal(
    countMatches([1, 2, 3], x => x >= 0),
    3);
  assert.equal(
    countMatches([-1, 2, -3], x => x < 0),
    2);
  assert.equal(
    countMatches([], x => x < 0),
    0);
  
  assert.equal(
    countMatches(['a', '', 'b'], x => x.length > 0),
    2);
  assert.equal(
    countMatches(['a', '', 'b'], x => x.length === 0),
    1);
});
