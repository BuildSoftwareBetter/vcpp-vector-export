#pragma once
#define _ITERATOR_DEBUG_LEVEL 0

#include <vector>



struct Key{
	char * key;
	int keySize;
};

/* 设备日志回调 */
typedef void(__cdecl *DevLogCallBack)(const int lLoginID, int nLogType, std::vector<Key> keys, int nkeysSize);

int test(int nSize, DevLogCallBack cb);