/* npm t exercises/arrays/sort_objects_test.mjs
Instructions:
- Create the file sort_objects.mjs
- Ensure this test passes
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {sortObjectsByName} from './sort_objects.mjs';

test('sortObjectsByName', t => {
	assert.deepEqual(
        sortObjectsByName([
            {name: 'C'},
            {name: 'b'},
            {name: 'Ä'},
            {name: 'd'},
        ]),
        [
            {name: 'Ä'},
            {name: 'b'},
            {name: 'C'},
            {name: 'd'},
        ]
    );
});
