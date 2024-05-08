class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
        this.val1 = value
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.val1 += value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.val1 -= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.val1 *= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if (value === 0)
            throw(new Error("Division by zero is not allowed"))
        this.val1 /= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.val1 = Math.pow(this.val1, value)
        return this
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.val1
    }
}