//给定一个字符串，把空格替换为 %20
//时间复杂度位 O(n)

#include <iostream>

using namespace std;

void replaceBlank(char string[], int length);

int main(int argc, char *argv[])
{
    char string[20] = {"we are happy."};
    for(int i = 0; i < 20; i++) {
        if (string[i] != '\0')
            cout << string[i];
    }
    cout << endl;

    replaceBlank(string, 20);

    for(int i = 0; i < 20; i++) {
        if (string[i] != '\0')
            cout << string[i];
    }

    cout << endl;
    return 0;
}

void replaceBlank(char string[], int length) { //注意这里的length是字符串的容量，而不是
     if (string == NULL)                      //实际长度
         return;
     int numBlank = 0;
     int size = 0;

     for (int i = 0; i < length; i++, size++) { //扫描字符串，
         if (string[i] == '\0') {               //计算字符串实际长度
             break;
         }
         if (string[i] == ' ') {                //计算字符串空格长度
             numBlank++;
         }
     }

     int newSize = size + numBlank * 2; //替换空格后的字符串的长度
     if (newSize < length) {            //应留有足够的空间扩展字符串
         for (int i = size, j = newSize; 0 <= i && i <= j; i--) {
             if (string[i] == ' ') {
                 string[j--] = '0';
                 string[j--] = '2';
                 string[j--] = '%';
             }
             else
                 string[j--] = string[i];
        }
     }

     return;
}
