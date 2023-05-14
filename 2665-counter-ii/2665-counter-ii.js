/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let data = init;
    return {
        increment :function(){
            data += 1;
            return data;
        },
        reset: function(){
            data = init;
            return data;
        },
        decrement: function(){
            data -= 1;
            return data;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */