int* twoSum(int *nums, int numSize, int target, int *returnSize)
{
	for (int i = 0; i < numSize; ++i) {
		for (int j = i+1; j < numSize; ++j) {
			if (nums[i]+nums[j]==target) {
				*returnSize = 2;
				int *ans = malloc(2*sizeof(int));
				ans[0] = i;
				ans[1] = j;
				return ans;
			}
		}
	}
	return NULL;
}
