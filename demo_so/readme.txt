实现一个so库文件名称为listupper.so，so文件中实现一个函数，函数名为void upper(const char *src, char *desc),调用update后将参数src所指向的字符串中所有字符转化为大写字母，结果放入desc字符串中。
分别用C语言编写一个程序，调用libupper.so中的upper函数，用C++语言编写一个程序，调用libupper.so中的upper函数。
test_c.c 为c语言函数
test_cpp.cpp 为C++函数