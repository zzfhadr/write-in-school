#include <stdio.h>
//#include "se.h"
void ano ()
{
	//int i=4;
	//printf("%d\n",i+4);
	printf("。H文件和。C文件并没有什么关联，INCLUDE。H相当于是给了一个名字，然后你在这个文件中说出这个名字，它会去他要找的地方找（不然的话就不会去，也就找不到），这个要找的地方，大概有两个一个是系统库，我不太清楚这个是在哪，还有就是你写的文件，如果用GCC就是你要连接在一起的文件，用这个的话，它自动把项目下的所有都连接在一起，。。因此，我SE2中不需要说出任何SE。H中的名字（直接定义了一个函数），就不用INCLUDE SE。H也行。\n");
	//其实我刚在https://wenku.baidu.com/view/0f5a0c5332b765ce0508763231126edb6f1a7624.html这看的说的，INCLUDE就是一个复制的宏，不仅可以复制。H文件也可以复制其他的文本文件。事实也正是这样，我在网上看到一些人，直接INCLUDE了。CPP文件。。。
}