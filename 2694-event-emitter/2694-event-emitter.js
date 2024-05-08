class EventEmitter {
    
    constructor(){
        this.map = new Map();
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        let arr  = this.map.get(eventName)
        if (arr)
            arr.push(callback)
        else
            arr = [callback]

        this.map.set(eventName, arr)
        return {
            unsubscribe: () => {
                if (this.map.get(eventName).length == 0)
                    this.map.delete(eventName)
                else
                    this.map.set(eventName, this.map.get(eventName).filter(item => item !== callback))
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        let results = []
        if (!this.map.has(eventName))
            return results

        this.map.get(eventName).forEach((fn) => {
            if (args.length)
                results.push(fn(...args))
            else
                results.push(fn())
        })
        return results
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */