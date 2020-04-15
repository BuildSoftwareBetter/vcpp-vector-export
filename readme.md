**问题描述：**
生成的dll接口使用了std::vector，调用dll的程序与dll不是发布版本（dll是release，exe是debug；或dll是debug，exe是release），出现vector调用异常。

***

项目代码链接：[vcpp-vector-export](https://github.com/BuildSoftwareBetter/vcpp-vector-export)

***

dll导出接口：

```cpp
struct Key{
	char * key;
	int keySize;
};

/* 设备日志回调 */
typedef void(__cdecl *DevLogCallBack)(const int lLoginID, int nLogType, std::vector<Key> keys, int nkeysSize);

int test(int nSize, DevLogCallBack cb);
```

在调用dll时，若dll和exe都为release，或者都为debug则没有问题；若两者发布版本不同则一定出问题。

查询msdn，发现是[Checked Iterators](https://docs.microsoft.com/en-us/cpp/standard-library/checked-iterators?view=vs-2019)的问题导致的。
可以将[_SECURE_SCL](https://docs.microsoft.com/en-us/cpp/standard-library/secure-scl?view=vs-2019)设置为0禁用Checked Iterators。更好的方式是修改[_ITERATOR_DEBUG_LEVEL](https://docs.microsoft.com/en-us/cpp/standard-library/iterator-debug-level?view=vs-2019)的值来修改_SECURE_SCL，设置Checked Iterators设置，使stl迭代器是否为调试模式。

在源文件中，在定义迭代器的任何标准库头之前指定_ITERATOR_DEBUG_LEVEL宏。

但是这不是解决问题的根本办法。

# 解决办法

**不要在导出函数中使用stl中的类型**，在不同的编译器中stl的实现可能不一样，会导致各种问题。最好的办法就是导出简单的类型，例如：语言自带的int、char、float等，或者使用c结构体，链表等自定义的简单类型。