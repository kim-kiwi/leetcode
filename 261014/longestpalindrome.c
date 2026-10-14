/*
흠... 어케 풀지
일단 O(N^2)은 가능할 거 같은데.
전체 글자 순회하면서 글자 하나마다 palindromic한지 확인하는거.
일단 구현해보자
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int is_palindrome(char *s, int len)
{
	char *end = s+len-1;
	while (end > s) {
		if (*s != *end) return 0;
		s++; end--;
	}
	return 1;
}

char *longestPalindrome(char *s)
{
	int len = strlen(s);
	for (int l = len; l > 0; --l) {
		for (int i = 0; i+l <= len; ++i) {
			if (is_palindrome(s+i, l)) {
				char *ans = malloc(l+1);
				memcpy(ans, s+i, l);
				ans[l] = '\0';
				return ans;
			}
		}
	}
	return NULL;
}

#include <stdio.h>

int main(void)
{
	char *s1 = "aba";
	char *s2 = "ababba";
	printf("%d, %d\n", is_palindrome(s1, strlen(s1)), is_palindrome(s2, strlen(s2)));
	printf("%d\n", is_palindrome(s2, 4));
	printf("%s\n", longestPalindrome(s1));
	printf("%s\n", longestPalindrome(s2));
	return 0;
}

/*
코드가 (하핫) 엄청 보기 좋아서 다 보이겠지만 (후훗) 대강 풀이 과정을 설명해보곘다.
우선 어떤 문자열이 palindrome인지 검사하는 함수를 작성하고, 그 함수를 기반으로 문자열을 탐색한다.
가장 큰 덩어리부터 검사하기 시작하면 처음 등장한 palindrome이 우리가 찾는 가장 긴 palindrome이 되게 된다.
(여러 정답이 있을 경우 둘 다 정답으로 쳐주기 때문에 가능하다.)
그렇기에 큰 덩어리부터 점차 줄여나가며 전체 문자열을 순회하고, 각 덩어리가 palindrome인지 검사한다.
그리고 palindrome을 찾으면 힙에 복사해서 반환해준다.

문제를 풀면서 생각을 할게 아니라 좀 더 문제를 직관적으로 바라보며 무엇이 필요한지 생각하니까
조금이나마 잘 풀린 게 아닐까 생각한다.

성능은 좀 구리지만 가독성이 뛰어나니 만족한다...
다음에 다시 풀 때는 성능을 우선해보고 싶다. 될진 모르겠다만...
*/
