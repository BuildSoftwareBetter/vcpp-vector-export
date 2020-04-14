#include "Api.h"

int test(int nSize, DevLogCallBack cb)
{
	std::vector<Key> keys;

	for (int i = 0; i < nSize; i++)
	{
		Key k;
		k.keySize = 10;
		k.key = new char[10];
		const char * tmp = "hello";
		memcpy(k.key, tmp, strlen(tmp));

		keys.push_back(k);
	}

	cb(1, 1, keys, nSize);

	return 100;
}