#pragma once
/*
��Դ�ļ��У��ڶ�����������κα�׼��ͷ֮ǰָ��_ITERATOR_DEBUG_LEVEL�ꡣ

_ITERATOR_DEBUG_LEVEL 0 �� ����_SECURE_SCL��0��
*/
#define _ITERATOR_DEBUG_LEVEL 0

#include <vector>

struct Key{
	char * key;
	int keySize;
};

/* �豸��־�ص� */
typedef void(__cdecl *DevLogCallBack)(const int lLoginID, int nLogType, std::vector<Key> keys, int nkeysSize);

int test(int nSize, DevLogCallBack cb);