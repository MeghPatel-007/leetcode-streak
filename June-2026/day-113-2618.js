/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj === null || obj === undefined || typeof classFunction !== 'function'){
        return false;
    }
    let currprototype = Object.getPrototypeOf(obj);
    while(currprototype !== null){
        if(currprototype === classFunction.prototype){
            return true;
        }else{
            currprototype = Object.getPrototypeOf(currprototype);
        }
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */

//* Another one

var checkIfInstanceOf = function(obj, classFunction) {
    if(obj === null || obj === undefined) return false;
    if(typeof classFunction !== 'function') return false;

    return Object(obj) instanceof classFunction;

};
