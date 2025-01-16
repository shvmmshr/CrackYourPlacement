Array.prototype.groupBy = function(fn) {
  return this.reduce((grouped, item) => {
    const key = fn(item);
    
    if (!grouped[key]) {
      grouped[key] = [];
    }
    
    grouped[key].push(item);
    
    return grouped;
  }, {});
};
