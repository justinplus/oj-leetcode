int removeDuplicates(int* nums, int numsSize) {
	int fore = 0, post = 1;
	for(; post < numsSize; post++){
		if( nums[fore] != nums[post] ){
			nums[++fore] = nums[post];
		}
	}

  // When nums is [], the length is not fore + 1
	return numsSize == 0 ? 0 : fore + 1;
}

