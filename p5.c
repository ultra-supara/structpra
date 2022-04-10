//共用体UNION について

#include <stdio.h>

union MyUnion {
    int i;
    double d;
    char c;
    char *str;
};

int main(){
    union MyUnion univ;

    univ.i = 200;
    printf("univ.i = %d\n", univ.i);

    univ.d = 95.25;
    printf("univ.d =  %f\n", univ.d);

    univ.c = 'A';
    printf("univ.c = %c\n",  univ.c);

    univ.str = "ABCDE";
    printf("u.str = %s\n", univ.str);

    return 0;
}
