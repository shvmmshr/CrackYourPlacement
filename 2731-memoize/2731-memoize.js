function memoize(fn) {
    const cache = {};
    return function(...args) {
      const key = String(args);
      if (key in cache) {
        return cache[key];
      }
      const result = fn(...args);
      cache[key] = result;
      return result;
    }
}