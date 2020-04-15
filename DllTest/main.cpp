#include "Api.h"
#include <stdio.h>

void CallBack(const int lLoginID, int nLogType, std::vector<Key> keys, int nkeysSize)
{
	printf("%d\r\n%d\r\n%d\r\n%d\r\n", lLoginID, nLogType, keys.size(), nkeysSize);
}

int main()
{

	test(11, CallBack);

	printf("ok");

	return 0;
}