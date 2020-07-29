/* npm t exercises/arrays/queue_via_array_test.mjs
Instructions:
– Implement the class Queue via an Array
*/

import test from 'ava';
import {strict as assert} from 'assert';

import {Queue} from './queue_via_array.mjs';

test('Using a queue', t => {
  const queue = new Queue();
  assert.equal(queue.length, 0);
  
  queue.enq('a');
  queue.enq('b');
  assert.equal(queue.length, 2);
  
  assert.equal(queue.deq(), 'a');
  assert.equal(queue.deq(), 'b');
  assert.equal(queue.length, 0);
  
  assert.throws(
    () => queue.deq(),
    { message: 'Queue is empty' });
});

test('Queue must not be a subclass of Array', t => {
  const queue = new Queue();
  assert.equal(queue instanceof Array, false);
});
