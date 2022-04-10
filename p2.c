#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char name[32];
    int age;
    double length ,weight, bmi;
};

int struct_input (struct Data *p) {
    char name[32];

    printf("名前__");
    fgets(name, sizeof(name), stdin);
    if(strchr(name, '\n') != NULL) {
        name[strlen(name) - 1] = '\0';
    } else {
        while(getchar() != '\n');
    }
    strcpy(p -> name, name);

    printf("年齢___");
    scanf("%d", &p -> age);

    printf("身長(cm)___");
    scanf("%lf", &p -> length);

    printf("体重(kg)___");
    scanf("%lf", &p -> weight);

    p -> bmi = p -> weight * 10000.0 / (p -> length * p -> length);

    return 0;
}

int main(){
    struct Data mydata;

    char format[] = "%s さん(%d 歳)のプロフィール\n"
                    "身長 = %5.1f cm , 体重 = %5.1f kg , BMI = %4.1f \n";

    char buffer[256];

    struct_input (&mydata);
    sprintf(buffer, format, mydata.name, mydata.age, mydata.length, mydata.weight, mydata.bmi);

    printf(buffer);
    return 0;
}
