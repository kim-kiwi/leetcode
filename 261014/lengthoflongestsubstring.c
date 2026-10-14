int lengthOfLongestSubstring(char *s)
{
	bool dup[256] = {0};
	char *cur = s;
	int count = 0;
	while (*cur) {
		if (dup[(unsigned char)*cur]) {
			 while (*s != *cur) {
				dup[*s] = 0;
				s++;
			}
			s++;
			dup[*s] = 1;
		}
		dup[(unsigned char)*cur] = 1;
		if (count < cur-s+1) count = cur-s+1;
		cur++;
	}
	return count;
}
