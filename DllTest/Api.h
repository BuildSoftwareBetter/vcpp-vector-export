#pragma once
/*
在源文件中，在定义迭代器的任何标准库头之前指定_ITERATOR_DEBUG_LEVEL宏。

_ITERATOR_DEBUG_LEVEL 0 ： 禁用_SECURE_SCL（0）
*/
#define _ITERATOR_DEBUG_LEVEL 0

#include <vector>

struct Key{
	char * key;
	int keySize;
};

/* 设备日志回调 */
typedef void(__cdecl *DevLogCallBack)(const int lLoginID, int nLogType, std::vector<Key> keys, int nkeysSize);

int test(int nSize, DevLogCallBack cb);