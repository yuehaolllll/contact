#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 负数在计算机中以补码的形式存在
/*
int main(){
    unsigned char a = -1;
    printf("%d\n",a);
    printf("%d %d %d %d",sizeof(bool),sizeof(char),sizeof(short),sizeof(int));
    return 0;
}
*/

//计算二进制中有几个1
/*
int count_number_of_1(int num){

    int count = 0;
    while(num){
        num = num & (num - 1);
        count++;
    }
    return count;
}


int main(){

    int count = 0;
    int num;
    scanf("%d", &num);
    count = count_number_of_1(num);
    printf("%d\n", count);

    return 0;

}
*/

//计算两个数的二进制中不同位的个数
/*
int count_number_diff(int a, int b){

    int ret = 0;
    int count = 0;
    ret = a^b;
    while(ret){
        ret = ret & (ret - 1);
        count++;
    }

    return count;
}

int main(){

    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int ret = count_number_diff(a,b);
    printf("%d\n", ret);

    return 0;

}
*/

//输出整数二进制中奇数位与偶数位
// 10: 00000000 00000000 00000000 00001010
// odd: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//even: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
/*
int odd(int a){

    int i = 0;
    int res = 0;
    for(i = 30; i >= 0; i -= 2){
        res = (a>>i)&1;
        printf("%d ",res);
    }
    return 0;
}

int even(int a){
    printf("\n");
    int i = 0;
    int res = 0;
    for(i = 31; i >= 1; i -= 2){
        res = (a>>i)&1;
        printf("%d ",res);
    }
    return 0;
}

int main(){

    int a = 0;
    scanf("%d", &a);
    odd(a);
    even(a);
    return 0;
}
*/

//检查编译器是小端存储还是大端存储
/*
int check(){
    int a = 1;
    return *((char*)&a);
}

int main(){

    int ret = check();
    if(ret == 1){
        printf("小端存储1\n");
    }else{
        printf("大端存储2\n");
    }
}

00000000 00000000 00000000 00001001   源码
01111111 11111111 11111111 11110110   反码
01111111 11111111 11111111 11110111   补码
*/


/*
int main(){

    int i = 0;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(i = 0; i <= 12; i++){
        arr[i] = 0;
        printf("hello world\n");

    }
    return 0;
}
*/


/*
int main(){

    int arr[5] = {1,2,3,4,5};

    int (*p)[5] = &arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%p\n", *p+i);
        printf("%d\n", *(*p+i));

    }

}
*/


/*
int main(){

    int arr[5] = {1,2,3,4,5};
    int* p = arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++){

        printf("%d\n", *(p+i));

    }

} 
*/

/*
int print1(int (*p)[5], int row, int col){

    int i = 0, j = 0;
    for(i  = 0; i < row; i++){

        for(j = 0; j < col; j++){

            printf("%d ", *(*(p+i)+j));

        }
        printf("\n");

    }
    return 0;
}

int main(){

    int arr[3][5] = {1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
    print1(arr, 3, 5);

    return 0;
}
*/

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = 1;
    int arr[2] = {};
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (*(nums + i) + *(nums + j) == target) {
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
    
    printf("[%d,%d]", arr[0],arr[1]);
    
    return 0;
}

int main(){
    int nums[] = {2,7,11,15};
    int target = 9;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize = 0;
    twoSum(nums, numsSize, target, &returnSize);
    
    return 0;

}
*/

/*

int main(){

    int arr[3] = {1,2,3};
    int (*p)[3] = &arr;
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < sz; i++){
        printf("%d\n", (*p)[i]);
    }
    return 0;

}
*/

/*
int main(){
    ( *( void (*)() )0 )();
    //以上代码是一次函数调用，0被强制类型转换为函数指针类型，里边存放的是这个无返回值的函数，然后通过*解引用，调用这个函数。

    void (* signal(int, void(*)(int)))(int);
} 
*/

//函数指针数组
/*
int Add(int a, int b){
    return a + b;
}

int Sub(int a, int b){
    return a - b;
}

int Mul(int a, int b){
    return a * b;
}

int Div(int a, int b){
    return a / b;
}

int main(){

    int (*arr[4])(int, int) = {Add, Sub, Mul, Div};
    int i = 0;
    for(i = 0; i < 4; i++){
        int ret = (*arr[i])(10, 5);
        printf("%d\n", ret);
    }

*/


/*
int main(){

    int arr[3] = {1,2,3};
    int (*p)[3] = &arr;
    printf("%d\n", sizeof(p+1));
    int i = 0;
    for(i  = 0; i < 3; i++){
        printf("%d\n", (*p)[i]);
    }

}
*/


//使用冒泡排序的思想实现模拟qsort函数
/*
void swap(char* buf1, char* buf2, int width){
    int i = 0;
    for(i = 0; i < width; i++){
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;
        buf1++;
        buf2++;
    }
}

void my_qsort(void* base, int size, int width, int (*cmp)(const void*, const void*)){

    char* p = (char*)base;
    int i, j = 0;
    for(i = 0; i < size - 1; i++){
        int flag = 1;
        for(j = 0; j < size - 1 - i; j++){
            if(cmp( p + j * width, p + (j + 1) * width) > 0){
                swap(p + j * width, p + (j + 1) * width, width);
                flag = 0;
            }
        }
        if(flag == 1){
            break;
        }
    }

}

int cmp_int(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(){

    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int width = sizeof(arr[0]);

    my_qsort(arr, sz, width, cmp_int);
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
*/


/*
int main(){

    int arr[5] = {1,2,3,4,5};
    int* p = (int*)(&arr+1);              //(&arr+1)是一个指针，指向arr数组的下一个元素的地址
    printf("%d %d\n", *(arr+1), *(p - 1));
}
*/

/*
int main(){

    int arr[4] = {1,2,3,4};
    int* p1 = (int*)(&arr+1);
    int* p2 = (int*)((int)arr + 1);
    printf("%x %x\n", p1[-1], *p2);
    
    //小端存储
    //01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
    //  ↑                                ↑           ↑
    //  p2                               p1[-1]      p1
    //因为p1[-1] = *(p1-1),所以p1[-1]->4
    //因为p2的类型是int*,p2向后访问4个字节,*p2->02 00 00 00
}
*/

/*
int main(){

    int arr[5][5] = {};
    int (*p)[4];
    p = arr;
    printf("%p, %d\n", &p[4][2]-&arr[4][2], &p[4][2]-&arr[4][2]);
    return 0;
}
*/

/*
int main(){

    int arr[2][5] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr1 = (int*)(&arr + 1);
    int* ptr2 = (int*)*(arr + 1);
    printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));

}
*/

/*
 int main(){

    char* arr[] = {"work", "at", "alibaba"};
    char** p = arr;
    p++;
    printf("%s\n", *p);
    return 0;

 }
*/


/*
int main(){

    char* arr[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char** parr[] = {arr+3, arr+2, arr+1, arr};
    char*** pparr = parr;

    printf("%s\n", **++pparr);
    printf("%s\n", *--*++pparr + 3);
    printf("%s\n", *pparr[-2] + 3);
    printf("%s\n", pparr[-1][-1] + 1);
    return 0;
}
*/

/*
// strlen函数返回的是size_t类型   size_t是无符号整形，即 unsigned int
// 模拟实现strlen
#include <assert.h>
size_t my_strlen(const char* str){

    size_t count = 0;
    assert(str);
    while(*str != '\0'){
        count++;
        str++;
    }
    return count;

}
int main(){

    char arr[] = "hello world";
    size_t n = my_strlen(arr);
    printf("%u\n", n);
    return 0;

}
*/

/*
//模拟实现strcpy函数
#include <assert.h>
char* my_strcpy(char* dest, const char* src){
    
    assert(dest && src);
    char* ret = dest;
    while(*dest++ = *src++){
        ;
    }
    return ret;

}
int main(){

    char arr1[] = "hello world";
    char arr2[20] = {};
    my_strcpy(arr2, arr1);
    printf("%s\n", arr2);
    return 0;

}
*/

/*
//模拟实现strcat函数
#include <assert.h>
char* my_strcat(char* dest, const char* src){

    assert(*dest && *src);
    char* ret = dest;
    while(*dest != '\0'){
        dest++;
    }
    while(*dest++ = *src++){
        ;
    }
    return ret;

}

int main(){

    char arr1[] = "hello";
    char arr2[] = " world";
    my_strcat(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}
*/

/*
//模拟实现strcmp函数
#include <assert.h>
int my_strcmp(const char* str1, const char* str2){

    assert(*str1 && *str2);
    while(*str1 == *str2){
        if(*str1 == '\0'){
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int main(){

    char arr1[] = "abc";
    char arr2[] = "abc";
    int ret = my_strcmp(arr1, arr2);
    if(ret > 0){
        printf(">\n");
    }
    else if(ret == 0)
    {
        printf("==\n");
    }
    else if(ret < 0){
        printf("<\n");
    }
    return 0;

}

*/


/*
//模拟实现strncpy函数
#include <assert.h>
char* my_strncpy(char* dest, const char* src, size_t n){

    assert(*dest && *src);
    char* ret = dest;
    while(n){
        *dest = *src;
    
        dest++;
        src++;
        n--;
    }

    return ret;

}
int main(){

    char arr1[] = "abcdefg";
    char arr2[] = "aaa";
    my_strncpy(arr1, arr2, 3);
    printf("%s\n", arr1);
    return 0;

}
*/


/*
//模拟实现strncat函数
#include <assert.h>
char* my_strncat(char* dest, const char* src, size_t n){

    assert(*dest && *src);
    char* ret = dest;
    while(*dest != '\0'){
        dest++;
    }
    while(n){
        if(*src == '\0'){
            *dest = '\0';
            return ret;
        }
        *dest = *src;
        dest++;
        src++;
        n--;

    }
    *dest = '\0';
    return ret;

}

int main(){

    char arr1[] = "hellox\0xxx";
    char arr2[] = "world";
    my_strncat(arr1, arr2, 7);
    printf("%s\n", arr1);
    return 0;

}
*/

/*
//模拟实现strncmp函数
#include <assert.h>
int my_strncmp(const char* str1, const char* str2, size_t n){

    assert(*str1 && *str2);
    int ret = 0;
    while(n){
        if(*str1 != *str2){
            if(*str1 > *str2){
                ret = 1;
            }else{
                ret = -1;
            }
            return ret;
        }
        str1++;
        str2++;
        n--;
    }
    return ret;

}
int main(){

    char arr1[] = "abcdef";
    char arr2[] = "abc";
    int ret = my_strncmp(arr1, arr2, 4);
    if(ret > 0){
        printf(">\n");
    }
    else if(ret == 0){
        printf("==\n");
    }
    else if(ret < 0){
        printf("<\n");
    }
    return 0;
}
*/

/*
//模拟实现strstr函数
#include <assert.h>
char* my_strstr(const char* str1, const char* str2){

    assert(*str1 && *str2);
    const char* p1 = str1;
    const char* p2 = str2;
    const char* start = str1;
    while(*start){
        p1 = start;
        p2 = str2;
        while(*p1 == *p2 && *p1 != '\0' && *p2 != '\0'){
            p1++;
            p2++;
        }
        if(*p2 == '\0'){
            return (char*)start;
        }
        start++;
    }
    return NULL;
}

int main(){

    char email[] = "proudyue@gmail.com";
    char substr[] = "gmail";
    char* ret = my_strstr(email, substr);
    if(ret == NULL){
        printf("substr inexistence\n");
    }else{
        printf("%s\n", ret);
    }
    return 0;
}
*/


/*
//strtok函数的使用
int main(){

    char arr[] = "proudyue0311@gmail.com";
    const char sep[] = "@.";
    char cp[30] = {0};
    strcpy(cp, arr);
    for(char* ret = strtok(cp, sep); ret != NULL; ret = strtok(NULL, sep)){

        printf("%s\n", ret);

    }
    return 0;
}
*/

/*
// strerror函数的使用
#include <errno.h>
int main(){

    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }else{
        
    }
    return 0;
}

*/


/*
#include <ctype.h>
int main(){

    int ret = isspace(' ');
    printf("%d\n", ret);
    int ret1 = isdigit('2');
    printf("%d\n", ret1);
    return 0;
}
*/



/*
//内存拷贝函数memcpy
int main(){

    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {0};

    memcpy(arr1+2, arr1, 20);
    for(int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++){
        printf("%d\n", arr1[i]);
    }
   return 0;
}
*/


/*
//模拟实现memcpy函数
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t n){
    assert(dest && src);
    void* ret = dest;
    while(n--){
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }
    return ret;

}

int main(){

    int arr1[] = {1,2,3,4,5};
    int arr2[10] = {0};
    my_memcpy(arr2, arr1, 20);
    for(int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        printf("%d\n", arr2[i]);
    }
    return 0;
}
*/

/*
//memmove函数的使用
int main(){

    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    memmove(arr1+2, arr1, 20);
    for(int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++){
        printf("%d\n", arr1[i]);
    }
    return 0;
    
}
*/

/*
//模拟实现memmove函数
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t n){
    assert(dest && src);
    void* ret = dest;
    if(dest < src){
        while(n--){
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }else{
        while(n--){
            *((char*)dest + n) = *((char*)src + n);
        }
    }
    return ret;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    my_memmove(arr+2, arr, 20);
    for(int i  = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}
*/

/*
//memset函数
int main(){

    char arr[] = "hello worshit";
    memset(arr+4, 'x', 5);
    printf("%s\n", arr);
    return 0;
}
*/

/*
//小乐乐改数字
int change_num(int num){
    int flag = 1;
    int sum = 0;
    int bit = 0;
    while(num){
        int temp = num % 10;//取出最后一位数字
        if(temp % 2 == 1){
            //如果是奇数
            bit = 1;
        }else{
            //如果是偶数
            bit = 0;
        }
        num = num / 10;
        sum += bit*flag;
        flag *= 10;
    }

    return sum;
}
int main(){

    int num = 0;
    scanf("%d", &num);
    int ret = change_num(num);
    printf("%d\n", ret);
    return 0;
}
*/


/*
//         * 
//       * *  
//     * * *
//   * * * * 
// * * * * *
int main(){

    int n = 0;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + j < n-1){
                    printf("  ");
                }else{
                    printf("* ");
                }
            }
            printf("\n");
        }
        return 0;
    }
    
}
*/


/*
//折扣活动

int main(){

    double price = 0.0;
    int m = 0;
    int d = 0;
    int flag = 0;
    scanf("%lf %d %d %d", &price, &m, &d, &flag);    // double 类型用%lf接收或打印
    if(m == 11 && d == 11){
        price = price * 0.7 - flag*50;
    }
    else if(m == 12 && d == 12){
        price = price * 0.8 - flag*50;
    }

    if(price < 0.0){
        printf("%2lf\n", 0);
    }else{
        printf("%2lf\n", price);
    }
    return 0;

}

*/


/*
int main(){

    char arr[1000] = {0};
    int i = 0;
    for(i = 0; i < 1000; i++){
        arr[i] = -1 - i;
    }
    printf("%d\n", strlen(arr));
    return 0;

}
*/

/*
//猜名次
int main(){

    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    for(A = 1; A <= 5; A++){
        for(B = 1; B <= 5; B++){
            for(C = 1; C <=5; C++){
                for(D = 1; D <= 5; D++){
                    for(E = 1; E <= 5; E++){
                        if(((B==2)+(A==3)==1) &&
                           ((B==2)+(E==4)==1) &&
                           ((C==1)+(D==2)==1) &&
                           ((C==5)+(D==3)==1) &&
                           ((E==4)+(A==1)==1) &&
                           (A*B*C*D*E == 120)){
                            printf("A:%d B:%d C:%d D:%d E:%d\n", A, B, C, D, E);
                           }
                    }
                }
            }
        }
    }

}
*/


/*
//猜凶手
int main(){

    int killer = 0;
    for(killer = 'a'; killer <= 'd'; killer++){
        if(((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3){
            printf("killer:%c\n", killer);
        }
    }


    return 0;
}
*/


//杨辉三角
/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

.....
*/
/*
int main(){

    int arr[10][10] = {0};
    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++){
        for(j = 0; j <= i; j++){
            if(j == 0 || j == i){
                arr[i][j] = 1;
            }
            if(i >= 2 && j >= 1){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    for(i = 0; i < 10; i++){
        for(int k = i; k < 20/2; k++){
            printf("  ");
        }
        for(j = 0; j <= i; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
//左旋字符串实现方法一
void left_rotate(char* arr, int k){
    int i = 0;
    int len = strlen(arr);
    if(k > len){
        k = k % len;
    }
    for(i = 0; i < k; i++){
        char temp = *(arr+0);
        int j = 0;
        for(j = 0; j < len - 1; j++){
            *(arr+j) = *(arr+j+1);
        }
        *(arr + len - 1) = temp;
    }
}
int main(){

    char arr[] = "abcdef";
    int k = 0;
    scanf("%d", &k);
    left_rotate(arr, k);
    printf("%s\n", arr);
    return 0;
}
*/



/*
//左旋字符串实现方法二
#include <assert.h>
void reverse(char* left, char* right){
    assert(left && right);
    while(left < right){
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
void left_rotate(char* arr, int k, int len){
    if(k > len){
        k = k % len;
    }
    reverse(arr, arr + k - 1);
    reverse(arr + k, arr + len - 1);
    reverse(arr, arr + len - 1);
}
int main(){

    char arr[] = "abcdef";
    int k = 0;
    int len = strlen(arr);
    scanf("%d", &k);
    left_rotate(arr, k, len);
    printf("%s\n", arr);
    return 0;
}
*/



/*
//杨氏矩阵方法一
// 1 2 3
// 4 5 6
// 7 8 9
struct Point{
    int x;
    int y;
};

struct Point find_num(int arr[3][3], int row, int col, int num){
    int x = 0;
    int y = col - 1;
    struct Point p;
    p.x = -1;
    p.y = -1;
    while(x < row && y >= 0){
        if(arr[x][y] < num){
            x++;
        }else if(arr[x][y] > num){
            y--;
        }
        else{
            p.x = x;
            p.y = y;
            return p;
        }
    }
    return p;
}

int main(){

    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int k = 0;
    scanf("%d", &k);
    struct Point ret = find_num(arr, 3, 3, k);
    printf("{%d, %d}\n", ret.x, ret.y);
    return 0;

}
*/

/*
//杨氏矩阵方法二
// 1 2 3
// 4 5 6
// 7 8 9
int find_num(int arr[3][3], int* row, int* col, int num){
    int x = 0;
    int y = *col - 1;
    while(x < *row && y >= 0){
        if(arr[x][y] < num){
            x++;
        }else if(arr[x][y] > num){
            y--;
        }else{
            *row = x;
            *col = y;
            return 1;
        }
    }
    return 0;
}
int main(){

    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
    int k = 0;
    scanf("%d", &k);
    int x = 3;
    int y = 3;
    int ret = find_num(arr, &x, &y, k);
    if(ret == 1){
        printf("{%d, %d}\n", x, y);
    }else{
        printf("can't find\n");
    }
    
    return 0;

}
*/


/*
//判断左旋字符串
void reverse(char* left, char* right){
    while(left < right){
        char box = *left;
        *left = *right;
        *right = box;
        left++;
        right--;
    }
}
#include <assert.h>
int is_left_rotate(char *s1, char* s2){
    assert(s1 && s2);
    int len = strlen(s1);
    int i = 0;
    for(i = 1; i < len+1; i++){
        reverse(s1, s1);
        reverse(s1+1, s1+len-1);
        reverse(s1, s1+len-1);
        if(strcmp(s2, s1) == 0){
            return 1;
        }
    }
    return 0;
}
int main(){

    char arr1[] = "abcdef";
    char arr2[] = "fabcde";
    int ret = is_left_rotate(arr1, arr2);
    if(ret == 1){
        printf("Yes\n");
    }else{
        printf("No");
    }

}
*/

/*
//判断左旋字符串(库函数法)
#include <assert.h>
int is_left_rotate(char* arr1, char* arr2){
    assert(arr1 && arr2);
    int len = strlen(arr1);
    strncat(arr1, arr1, len);
    for(int i = 0; i < len; i++){
        if(strncmp(arr2, arr1+i, len) == 0){
            return 1;
        }
    }
    return 0;   
}

int main(){

    char arr1[20] = "abcdef";
    char arr2[] = "abcde";
    int ret = is_left_rotate(arr1, arr2);
    if(ret == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
*/

/*
//利用冒泡排序的思想模拟实现qsort函数
void exchange(char* buf1, char* buf2, int width){
    int i = 0;
    for(i = 0; i < width-1; i++){
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;
        buf1++;
        buf2++;
    }
}
void my_qsort(void* base, int len, int width, int(*cmp)(void* buf1, void* buf2)){
    char* q = (char*)base;
    for(int i = 0; i < len-1; i++){
        int flag = 1;
        for(int j = 0; j < len - i - 1; j++){
            if(cmp(q+j*width, q+(j+1)*width) > 0){
                exchange(q+j*width, q+(j+1)*width, width);
                flag = 0;
            }
        }
        if(flag == 1){
            break;
        }
    }
}
int cmp(void* buf1, void* buf2){
    return *(int*)buf1 - *(int*)buf2;
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int width = sizeof(arr[0]);
    my_qsort(arr, len, width, cmp);
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
*/

/*
int main(){
    int arr[2][5] = {10,9,8,7,6,5,4,3,2,1};
    int* ptr1 = (int*)(&arr + 1);
    int* ptr2 = (int*)(*(arr + 1));
    printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
    return 0;
}
*/

/*
int main(){
    int arr[5] = {5,4,3,2,1};
    int* ptr = (int*)(&arr + 1);
    printf("%d %d\n", *(arr + 1), *(ptr - 1));
    return 0;
}
*/

/*
//矩阵转置
int main(){

    int row = 0;
    int col = 0;
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]); 
        }
    }
    for(int j = 0; j < col; j++){
        for(int i = 0; i < row; i++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/


/*
//上三角矩阵判断
int main(){

    int n = 0;
    scanf("%d", &n);
    int arr[n][n];
    for(int i  = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){                  //下部分如果出现不为0
                if(arr[i][j] != 0){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;

}
*/

/*
//有序序列判断
int main(){

    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //判断（升序）
    int flag1 = 0;
    int flag2 = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            flag2 = 1;
        }
        else if(arr[i] < arr[i+1]){
            flag1 = 1;
        }
        else{
            ;
        }
    }
    if(flag1 + flag2 <= 1){
        printf("Sorted\n");
    }else{
        printf("Unsorted\n");
    }
    return 0;

}
*/

/*
//结构体传参
struct S
{
    int arr[100];
    int num;
};
void print1(struct S ss){
    for(int i = 0; i < 3; i++){
        printf("%d ", ss.arr[i]);
    }
    printf("%d\n", ss.num);
}
void print2(struct S* ps){
    for(int i = 0; i < 3; i++){
        printf("%d ", ps->arr[i]);
    }
    printf("%d\n", ps->num);
}
int main(){

    struct S s = {{1,2,3}, 100};
    print1(s);    //传值调用
    print2(&s);   //传址调用（高效，节省空间）
    return 0;
}
*/

/*
//用共用体实现检测系统的大小端存储
int main()
{

    union U // 共用一块内存
    {
        char c;
        int i;
    }u;
    u.i = 1;
    if(u.c == 1){
        printf("小端\n");
    }else{
        printf("大端\n");
    }
    return 0;
}
*/

/*
//malloc函数的使用 
#include <errno.h>
#include <stdlib.h>
int main(){

    int* p = (int*)malloc(40);
    if(p == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }
    int i = 0;
    for(i = 0; i < 10; i++){
        *(p+i) = i;
    }
    for(i = 0; i < 10; i++){
        printf("%d ", *(p+i));
    }

    free(p);
    p = NULL;

    return 0;
}
*/

/*
//calloc函数的使用
#include <errno.h>
#include <stdlib.h>
int main(){

    int* p = (int*)calloc(10, sizeof(int));
    if(p == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("%d ", *(p+i));

    }

    free(p);
    p = NULL;

    return 0;

}
*/


/*
//realloc函数的使用
#include <errno.h>
#include <stdlib.h>

int main(){

    int* p = (int*)malloc(40);
    if(p == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }
    int i = 0;
    for(i = 0; i < 10; i++){
        *(p+i) = i+1;
    }
    int* ptr = (int*)realloc(p, 80);
    if(ptr == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }
    p = ptr;
    for(i = 0; i < 10; i++){
        printf("%d ", *(p+i));
    }
    free(p);
    p = NULL;

    return 0;

}
*/


/*
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void GetMemory(char** p){
    *p = (char*)malloc(100);
}
int Test(){
    char* str = NULL;
    GetMemory(&str);
    if(str == NULL){
        printf("%s\n", strerror(errno));
        return 1;
    }

    strcpy(str, "hello world");
    printf("%s\n", str);

    free(str);
    str = NULL;
    return 0;
}
int main(){
    Test();
    return 0;
}
*/


/*
//最大公约数与最小公倍数之和
int main(){

    int n = 0;
    int m = 0;
    while(scanf("%d %d", &n, &m) == 2){
        int min = n > m ? n : m;
        int max = n < m ? n : m;
        int r = 0;
        while(r = max % min){       // 寻找最大公约数
            max = min;
            min = r;
        }

        // 最小公倍数
        int lcm = n*m / min;
        printf("%d\n", min + lcm);

    }
    
    return 0;

}
*/

//打印空心正方形
int main(){

    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;    

}



