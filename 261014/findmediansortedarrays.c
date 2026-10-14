#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int *ans = malloc(sizeof(int)*(nums1Size+nums2Size));
	int x = 0, y = 0;
	for (int i = 0; i < nums1Size+nums2Size; ++i) {
		int a = x<nums1Size ? nums1[x] : 2147483647;
		int b = y<nums2Size ? nums2[y] : 2147483647;
		if (a < b) {
			ans[i] = a;
			x++;
		} else {
			ans[i] = b;
			y++;
		}
	}
	double foo = 0;
	if ((nums1Size+nums2Size)%2==0) {
		foo = (ans[(nums1Size+nums2Size)/2-1]+ans[(nums1Size+nums2Size)/2])/2.0;
	} else {
		foo = ans[(nums1Size+nums2Size)/2];
	}
	free(ans);
	return foo;
}

int main(void)
{
	int a[2] = {1,3};
	int b[1] = {2};
	printf("%.2f\n", findMedianSortedArrays(a, 2, b, 1));
	return 0;
}
