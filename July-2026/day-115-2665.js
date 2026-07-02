/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let original = init
  return {
    reset: () => {
      init = original
      return original
    },
    increment: () => {
      return ++init
    },
    decrement: () => {
      return --init
    },
  }
}

//  const counter = createCounter(5)
//  counter.increment(); // 6
//  counter.reset(); // 5
//  counter.decrement(); // 4
