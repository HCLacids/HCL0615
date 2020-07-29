/* npm t exercises/arrays/replace_objects_test.mjs
Instructions:
– Implement replace_objects.mjs so that the test passes.
– Use Array.prototype.flatMap() to do so.
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {replaceObjects} from './replace_objects.mjs';

test('replaceObjects', t => {
  assert.deepEqual(
    replaceObjects([
      { value: 'a', repeat: 1 },
      { value: 'b', repeat: 0 },
      { value: 'c', repeat: 3 },
    ]),
    ['a', 'c', 'c', 'c']
  );
  assert.deepEqual(
    replaceObjects([
      { value: 1, repeat: 1 },
      { value: 2, repeat: 2 },
      { value: 3, repeat: 3 },
    ]),
    [1, 2,2, 3,3,3]
  );
  assert.deepEqual(
    replaceObjects([]),
    []
  );
});
