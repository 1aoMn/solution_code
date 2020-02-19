/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
    this.nums = nums;
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function() {
    return this.nums;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
    let ans=this.nums.slice(),len=this.nums.length,i;
    while(len>0){
        i=Math.floor(Math.random()*len);
        len--;
        let t=ans[i];
        ans[i]=ans[len];
        ans[len]=t;
    }
    return ans;

};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */