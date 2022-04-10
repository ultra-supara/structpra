//メンバに同じ型のポインタをもつ構造体である
//自己参照構造体について学習します

#include <stdio.h>

typedef struct Data {
    char name[32];
    int age;
    // self-referential structure↓
    struct Data *nextdata;
} MyDataType;

int main() {
    MyDataType a = {"gsan", 27};
    MyDataType b = {"asupara", 21};
    MyDataType c = {"tamanegi", 17};

    MyDataType *lpdata;
    a.nextdata = &b;
    b.nextdata = &c;
    c.nextdata = NULL;

    for (lpdata = &a; lpdata; lpdata = lpdata -> nextdata)  {
        printf("%s (%d)\n", lpdata->name, lpdata->age);
    }

    return 0;
}
