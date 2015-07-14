int removeDuplicates(int* nums, int numsSize) {
	int fore = 0, post = 1;
	for(; post < numsSize; post++){
		if( nums[fore] != nums[post] ){
			nums[++fore] = nums[post];
		}
	}
	return fore + 1 > numsSize ? numsSize : fore + 1;
}

// When nums is [], the length is not fore + 1