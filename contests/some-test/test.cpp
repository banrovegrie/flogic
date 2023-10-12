#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    str1 = str2;
    printf("%s %s", str1, str2);
}