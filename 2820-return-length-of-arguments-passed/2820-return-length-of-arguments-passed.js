/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(arg) {
    return arguments.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */