#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10]= &arr;
//	int(*pfArr[4])(int, int);
//	int(*(ppfArr)[4])(int, int) = &pfArr;
//	
//
//	return 0;
//}
	
//qsort库函数的使用

//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int cmp_float(const void* e1, const void* e2)
//{
//	return *(float*)e1 - *(int*)e2;
//}
//void test()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	float f[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };
//	int sz2 = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz2, sizeof(f[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz2; i++)
//	{
//		printf("%.2f ", f[i]);
//	}
//}
//int main()
//{
//	test();
//}

//com_float 函数优化
//int cmp_float(const void* e1, const void* e2)
//{
//	if (*(float*)e1 == *(float*)e2)
//		return 0;
//	else if (*(float*)e1 > *(float*)e2)
//		return 1;
//	else
//		return -1;
//}


//写一段代码告诉我们当前机器的字节序是什么
//int a = 1;
//char* p = (char*)&a;
//if (*p == 1)
//{
//	printf("小端");
//}
//else
//{
//	printf("大端")；
//}


//字符数组
//char arr = { 'a','b','c','d','e','f' };
//printf("%d\n", sizeof(arr));//计算的是数组大小 6*1=6字节
//printf("%d\n", sizeof(arr + 0));//4/8 arr是首元素的地址，arr+0还是首元素的地址 地址的大小是4、8字节
//printf("%d\n", sizeof(*arr));//1  arr是首元素的地址，*arr就是首元素，首元素是字符大小是一个字节
//printf("%d\n", sizeof(arr[1]));//1
//printf("%d\n", sizeof(&arr));//&arr 虽然是数组的地址，但是还是地址，地址大小是4/8个字节
//printf("%d\n", sizeof(&arr + 1));//&arr+1 是跳过整个数组后的地址，地址大小是4/8个字节
//printf("%d\n", sizeof(&arr[0] + 1));//4/8 第二个元素的地址


//printf("%d\n", strlen(arr));//随机值
//printf("%d\n", strlen(arr + 0));//随机值
////printf("%d\n", strlen(*arr));//err
////printf("%d\n", strlen(arr[1]));//err 
//printf("%d\n", strlen(&arr));//随机值
//printf("%d\n", strlen(&arr + 1));//随机值-6
//printf("%d\n", strlen(&arr[0] + 1));//随机值

//char arr[] = "abcdef";
//printf("%d\n", sizeof(arr));//sizeof(arr)的计算的数组的大小，单位是字节：7
//printf("%d\n", sizeof(arr + 0));//计算的是地址，地址的大小是4/8
//printf("%d\n", sizeof(*arr));//*arr是首元素，sizeof(*arr)计算首元素的大小：1
//printf("%d\n", sizeof(arr[1]));//计算第二个元素的大小：1
//printf("%d\n", sizeof(&arr));//计算&arr的大小，地址大小是4/8
//printf("%d\n", sizeof(&arr + 1));//计算跳过一个数组后的地址，地址大小为：4/8
//printf("%d\n", sizeof(&arr[0] + 1));//&arr[0]+1是第二个元素的地址，地址大小为：4/8
//
//char arr[] = "abcdef";
//printf("%d\n", strlen(arr));//计算字符串长度 6
//printf("%d\n", strlen(arr + 0));//arr+0还是首元素的地址 6
//printf("%d\n", strlen(*arr));//非法访问 err
//printf("%d\n", strlen(arr[1]));//非法访问 err
//printf("%d\n", strlen(&arr));//传arr地址计算arr长度 6
//printf("%d\n", strlen(&arr + 1));//跳过一个arr大小的数组计算后面元素的大小 随机
//printf("%d\n", strlen(&arr[0] + 1));//&arr[0]+1跳过了首元素计算剩余元素大小 5

 //char *p[] = "abcdef";
 //printf("%d\n", strlen(p));// 6
 //printf("%d\n", strlen(p + 1));// 5
 //printf("%d\n", strlen(*p));// err
 //printf("%d\n", strlen(p[0]));// err
 //printf("%d\n", strlen());// 随机值
 //printf("%d\n", strlen(&p + 1));// 随机值
 //printf("%d\n", strlen(&p[0] + 1));// 5
//
//int a[3][4] = { 0 };
//printf("%\n", sizeof(a));
//printf("%\n", sizeof(a[0][0]));
//printf("%\n", sizeof(a[0]));
//printf("%\n", sizeof(a[0] + 1));
//printf("%\n", sizeof(*(a[0] + 1)));
//printf("%\n", sizeof(&a[0] + 1));
//printf("%\n", sizeof(*a));
//printf("%\n", sizeof(a[3]));
//
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d\n", *(a + 1), *(ptr - 1));
//	return 0;
//}
//  
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
////假设p 的值为0x100000。如下表达式的值分别是多少？
////以知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//} a[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",5} }
//;
//int main()
//{
//	printf("%s", a[0].name);
//	return 0;
//}

//
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}
//
//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00

//#include<stdio.h>
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d", *pulPtr, *(pulPtr + 3));
//	return 0;
//}
//喝汽水问题 一瓶汽水1元 两个空瓶 可以换一瓶汽水 问 20快钱 可以喝多少汽水  
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	printf("钱数");
//	scanf_s("%d", &money);
//	total= money;
//	empty = total;
//	while (empty > 1)
//	{
//		total = total + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	
//	printf("%d\n",total);
//	return 0;
//}
//
////使数组里的奇数全部位于偶数前面
//void move(int A[], int Sz)
//{
//	int i = 0;
//	int j = 0;
//	int r = 0;
//	int h = 0;
//	for (i = 0; i < Sz; i++)
//	{ 
//		if (A[i] % 2 != 0)
//		{
//			j = A[i];
//			r = A[h];
//			A[h] = j;
//			A[i] = r;
//			h++;
//		}
//
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d",a+b,c);
//	return 0;
//}
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", strlen(a));
//	return 0;
//}
//int main()
//{
//	unsigned int a = 0x1234;
//	unsigned char b = *(unsigned char*)&a;
//	printf("%d\n", b);
//	return 0;
//}
//杨辉三角
//
//猜凶手
//A说：不是我
//B说：是C
//C说：是D
//D说：C在胡说
//已知3个人说了真话，1个人说了假话
//现在根据这些信息，写一个程序来判断谁是凶手
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		printf("KILLER=%c",killer);
//	}
//	return 0;
//}
//赛马问题
//有36匹马 6个跑道 没有计时器 请赛马确定 36匹中的前三名
//请问最少赛马几次
//赛马问题
// 有25匹马 5个跑道 没有计时器 请赛马确定 25匹马中的前三名
// 请问最少赛几次
//
//LS指令
//语法:[选项][目录或文件夹]
//功能:对于目录，该命令列出该目录下所有子目录与文件。对于文件，将列出文件名以及其他信息。
//常用选项：
//* -a 列出目录下的所有文件，包括以，开头的隐藏文件。
//* -d 将目录文件一样显示，而不是显示其下的文件，如：ls -d指定目录
//* -i 输出文件的i节点的索引信息。如ls -ai指定文件
//* -k 以k字节的形式表示文件的大小。ls -alk指定文件
//* -l列出文件的详细信息
//* -t以时间排序。
//* -R列出所有子目录下的文件（递归）
//pwd命令
//语法：pwd
//功能：显示用户当前所在位置
//
//cd指令
//Linux系统中，磁盘上的文件和目录被组成一颗目录树，每个节点都是目录或文件
//语法：cd目录名
//功能：改变工作目录，将当前工作目录改变到指定目录下。
//
//touch指令
//语法：touch[选项]...文件...
//功能：touch命令参数可改变文档或目录的日期时间，包括存取时间和更改时间，或者新建一个不存在的文件
//常用选项：
//* -a 或 -time=atime 或 --time=access 或 -time=use 只更改存取时间
//* -d 使用指定的日期和时间，而非现在的时间。
//* -f 此参数将忽略不予处理，仅负责解决BSD版本touch指令的兼容性问题
//* -m 或--time=mtime 或 --time=modify 只更改变动时间。
//* -r 把指定文档或目录的时间，统统设成和参考文档或目录的日期时间相同
//* -t 使用指定的日期时间，而非现在的时间。
//typedef struct Wuhu
//{
//	int name[10];
//	int age;
//	struct wuhu* next;
//}Wuhu;
//int main()
//{
//	int i = 0,j=0;
//	printf("输入次数");
//	scanf_s("%d", j);
//	struct Wuhu* p, * fist, * end;
//	for (i = 0; i < j; i++)
//	{
//		p = (Wuhu*)malloc(sizeof(Wuhu));
//		printf("请输入");
//		scanf_s("%d", p->name);
//		scanf_s("%d", p->age);
//		fist = p;
//		end = p;
//		end->next = NULL;
//	}
//	return 0;
//}
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int *ptr1 = (int *)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//}
//
//int main()
//{
//    int input = 2019;
//    int add = 0;
//    int q = 0;
//    int b = 0;
//    int g = 0;
//    for (input = 2019; input > 0; input--)
//    {
//        q = input % 1000;
//        if (q == 9)
//        {
//            add++;
//            continue;
//        }
//        b = input % 100;
//        if (b == 9)
//        {
//            add++;
//            continue;
//        }
//        g = input % 10;
//        if (g == 9)
//        {
//            add++;
//            continue;
//        }
//
//    }
//    printf("%d", add);
//    return 0;
//}
//typedef struct wuhu
//{
//	int number[10];
//	int march[3];
//	struct wuhu* next;
//}wuhu;
//int mian()
//{
//	struct wuhu* p, * fist, * end;
//	p = (wuhu*)malloc(sizeof(wuhu));
//	scanf("%d", p->number);
//	scanf("%d", p->march);
//	fist = p;
//	end = p;
//	end->next = NULL;
//	p = (wuhu*)malloc(sizeof(wuhu));
//	scanf("%d", p->number);
//	scanf("%d", p->march);
//	p = p->next;
//  end = p;
//  end->next = NULL;
//
//}
//typedef struct wuhu
//{
//	int number;
//	struct wuhu* next;
//}wuhu;
//int main()
//{
//	int i = 0;
//	int input = 0;
//	struct wuhu* fist, * p, * end;
//	printf("请输入数据个数:>");
//	scanf_s("%d", &input);//单链长度
//	for (i = 0; i < input; i++)
//	{
//
//      p = (wuhu*)malloc(sizeof(wuhu));
//	  p->number = 1;//赋值
//	    if (i == 0)
//	    {
//		   fist = p;//指向首元素首地址地址
//		   end = p;
//		   end->next = NULL;//尾指针设空
//	    }
//	    else
//	    {
//		   p->next = p;
//		   end = p;
//		   end->next = NULL;//尾指针设空
//	    }
//		printf("%d", p->number);
//		p = p->next;
//	}
//	int dingdan;
//	printf("请输入要查询的订单:>");
//	scanf_s("%d", &dingdan);
//	p = fist;
//	while (p != NULL)
//	{
//		if (p->number == dingdan)
//		{
//			break;
//		}
//		p = p->next;
//	    if (p == NULL)
//		{
//			printf("not found");
//		}
//	}
//return 0;
//}
//
//strcat
//. Appends a copy of the source string to the destination string. The terminating null
//  character in destination is overwritten by the first character of source,and a null
//  -character is included at the end of the new string formed by the concatenation of
//  both in destination.
//. 源字符必须以'\0'结束
//. 目标空间必须足够大，能容纳下源字符串的内容
//. 目标空间必须可修改
//
//strcmp
//. This function starts comparing the first character of each string. If they are equal
//  to each other,it continues with the following pairs until the characters differ or 
//  until a terminating null-character is reached
//. 第一个字符串大于第二个字符串，则返大于0的数字
//. 第一个字符串等于第二个字符串，则返回0
//. 第一个字符串小于第二个字符串，则返回小于0的数字
//
//strncpy
//. Copies the first num characters of source to destination, If the end of the source C 
//  string(which is signaled by a null - character) is found before num characters have 
//  been copied, destination is padded with zeros until a total of num characters have 
//  been written to it.
//. 拷贝num个字符从源字符串到目标空间。
//. 如果源字符串的长度小于num, 则拷贝完源字符串之后, 在目标的后边追加0, 直到num个。
//
//
//strncat
//· Appends the first num characters of source to destination, plus a terminating null - character.
//. If the length of the C string in source is less than num, only the content up to the terminating
//  null - character is copied.

//int main()
//{
//	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//	int n;
//	puts("Looking for R2 astromech droids...");
//	for (n = 0; n < 3; n++)
//	{
//		if (strncmp(str[n], "R2xx", 2) == 0)
//		{
//			printf("found %s\n", str[n]);
//		}
//	}
//	return 0;
//}

//strtok
//char*strtok(char t str, const char t sep);
//. sep参数是个字符串, 定义了用作分隔符的字符集合。
//. 第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
//  strtok函数找到str中的下一 个标记, 并将其用\0结尾, 返回一个指向这个标记的指针。(注: strtok
//  函数会改变被操作的字符串, 所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。)
//. strtok函数的第一 个参 数不为NULL, 函数将找到str中第一个标记, strtok函数将保存它在字符串中的位置。
//. strtok函数的第一 个参数为NULL, 函数将在同一个字符串中被保存的位置开始, 查找下一个标记。
//. 如果字符串中不存在更多的标记, 则返回NULL指针。
/*int main()
{
	char arr[] = "123456@234.com";
	char* p = "@.";
	char buf[1024] = { 0 };
	strcpy(buf, arr);
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	return 0;
}

*/
//
//函数       如果他的参数符合下列条件就返回真
//
//iscntrl   控制任何字符
//isspace   空白字符：空格' ',换页'\f',换行'\n',回车'\r',制表符'\t'或者垂直制表符'\v'
//isdigit   十进制数字 0~9
//isxdigit  十六进制数字，包括所以十进制数字，小写字母a~f，大写字母A~F
//islower   小写字母a~z
//issupper  字母A~Z
//isalpha   字母a~z或A~Z
//isalnum   字母或者数字，a~z,A~Z,0~9
//ispunct   标点符号，任何不属于数字或者字母的图形字符（可打印）
//isgraph   任何图形字符
//isprint   任何可打印字符，包括图形字符和空白字符
//int main()
//{
	//错误码  错误信息
	//  0  -  No error     
	//  1  -  Operation not permitted 
	//  2  -  No such file or directory
	// ...
	//errno 是一个全局的错误码的变量
	//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码
	//赋值到errno中
	//char* str = strerror(errno);
	//printf("%s", str);
	//return 0;
//}

//void* memcpy(void* destination，const void* source， size_ t num);
//. 函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
//. 这个函数在遇到'\0'的时候并不会停下来。
//. 如果source和destination有任何的重叠,复制的结果都是未定义的。
// 
//. 和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
//. 如果源空间和目标空间出现重叠，就得使用memmove函数处理。
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}

//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}
//int main()
//{
//	//01 00 00 00 02 00 00 00 03 00 00 ...
//	//01 00 00 00 02 00 00 00 05 00 00 ...
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 }; 
//	int ret = memcmp(arr1, arr2, 9);//对比的大小单位是字符
//	printf("%d\n", ret);
//	return 0;
//}
//int main()
//{
//	char arr[10] = "";
//	memset(arr,'#',10);
	//int arr[10] = { 0 };
	//memset(arr, 1, 10);
	//          err 因为设置的内存大小是字符串
	//小端储存中  00 00 00 00 00 00 00 00 00 ...
	//  被设置为  01 01 01 01 01 01 01 01 01 ...
//}
//struct stu
//{
//	char name[10];
//	char telnumber[30];
//}stu4;//全局变量
//
//struct stu stu3;//全局变量
//
//int main()
//{
//	struct stu stu1;//局部变量
//	struct stu stu2;//局部变量
//	return 0;
//}

//匿名结构体类型
//struct
//{
//	char name[20];
//	int age;
//}x;//只能使用x变量 无法创建新的变量

//struct A
//{
//	int a;
//	struct A a;//err
//};
//struct B
//{
//	int a;
//	struct B* next;
//};
//
//
//typedef struct Node
//{
//	int a;
//}node;//typedef 将struct Node重命名为node
//typedef struct Wuhu
//{
//	char s;
//	char a;
//	int d;
//	char arr[30];
//}wuhu;
//int main()
//{
//    wuhu hh = {'s','a',6,"helloworld"};
//	printf("%c %c %d %s", hh.s, hh.a, hh.d, hh.arr);
//	return 0;
//}

//
//如何计算 ？首先得掌握结构体的对齐规则：
//     1.第一个成员与结构体变量偏移量为0的地址处。
//	 2.其他成员变量要对齐到某个数字(对齐数)的整数倍的地址处。
//对齐数 = 编译器默认的第一个对齐数 与 该成员大小的较小值。
//    vs 中默认的值为8。
//	 3.结构体总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍。
//	 4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大的整数倍处，
//	   结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍。

//为什么存在内穿对齐？
//   大部分的参考资料都是这么说的(没有官方解释)
//   1.平台原因(移植原因):不是所有硬件平台都 能访问任意地址上的任意数据；
//	                  某些硬件平台只能在某些地址处取某些特定类型的数据
//                      否则抛出硬件异常。
//   2.性能原因:数据结构(尤其是栈)应该尽可能的在自然界边界上对齐。原因在与
//	         为了访问未对齐的内存，处理器需要做两次内存访问；而对齐的内存
//	         访问仅仅需要一次访问。
//总体来说：结构体的内存对齐是拿空间来换取时间的做法。

//位段的内存分派
//1.位段的成员可以是 int,unsigned int,signed int 或者是 char (属于整形家族)类型
//2.位段的空间上是按照需要以4个字节(int)或者1个字节(char)的方式来开辟的。
//3.位段涉及很多不确定因素，位段是不跨平台的，注意可移植的程序应该避免使用位段。

//枚举的优点
//为什么使用枚举？
//我们可以使用#define定义常量，为什么非要使用枚举？
//枚举的优点：
//1.增加代码的可读性和可维护性。
//2.和#define定义的标识符比较枚举有类型检查，更加严谨。
//3.防止了命名污染（封装）。
//4.便于调试。
//5.使用方便，一次可以定义多个变量。

//typedef struct stu
//{
//	char name[10];
//	char telnumber[30];
//	char a;
//	int age;
//}wuhu;
//int main()
//{
//	int i;
//	wuhu a = { "abcde","1234",'a',10 };
//	return 0;
//	i=strlen(wuhu);
//	printf("%d", i);
//}

//struct A
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//};

//enum Sex
//{
//	MALE = 2,
//    FEMALE = 3,
//	secret=0
//};
//int main()
//{
//	enum Set s = MALE;
//	return 0;
//}
//
//union Un
//{
//	char i;
//	int j;
//};
//int main()
//{
//
//}
//int main()
//{
//	int x = 0;
//	int* a;
//	a = &x;
//	printf("%p",a);
//
//}
//C语言提供了一个动态内存开辟的函数
//void* malloc(sizeof(size_t size));
//这个函数向内存申请一块连续可用的空间，并返回指向这块空间在指针。
//-如果开辟成功，则返回一个指向开辟好空间的指针。
//-如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
//-返回值的类型是void*，所以malloc函数并不知道开辟的空间的类型，具体
// 在使用的时候使用者自己去决定。
//-如果参数size为0，malloc的行为是标准未定义的，取决于编译器。

//C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的
//void free(void* ptr);
//free函数用来释放动态开辟的内存
//-如果函数ptr指向的空间不是动态开辟的，那free函数的行为的未定义的。
//-如果函数ptr是NULL指针，则函数什么事都不做。


//int main()
//{
//	//向内存申请10个整形的空间
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d".*(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;
//	return 0;
//}

//C语言还提供了一个函数叫calloc, calloc函数也用来动态内存分配
//
// 原型： void* calloc(size_t num, size_t size);
//-函数的功能是为num个大小为size的元素开辟一块空间，并且把空间
// 的每个字节初始化为0.
//-与malloc的区别只在于calloc会在返回地址之前把申请的空间的每个
// 字节初始化为全0.

int main()
{
	//malloc(10*sizeof(int));
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + 1));
		}
	}
	//释放空间
	//free函数是用来释放动态开辟的空间的
	free(p);
	p = NULL;
	return 0;
}







