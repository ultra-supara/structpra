#define STUDENTNO 5; //生徒の数 (taxas, tamanegi, gsan, sabamiso, ringo)
#define SUBJECTNO 3; //かもくすう(japanese, math, english)

#include <stdio.h>

struct Seiseki {
    char name[32];
    int japanese;
    int math;
    int english;
};

int main () {

    struct Seiseki electic3[5] = {
        {"texas", 80, 80, 55},
        {"tamanegi", 75, 90, 70},
        {"gsan", 50, 45, 30},
        {"sabamiso", 100, 55, 90},
        {"ringo", 60, 85, 35},
    };

    int i, sum0 = 0, sum1[3], sum2[5];

    for (i = 0; i < 3; i++){
        sum1[i] = 0; // それぞれの科目の合計点を知りたい
    }
    for (i = 0; i < 5; i++){
        sum2[i] = 0; // すべての点数の合計点が知りたい
    }

    for (i = 0; i < 5; i++){
        sum1[0] += electic3[i].japanese;
        sum1[1] += electic3[i].math;
        sum1[2] += electic3[i].english;
    }

    for (i = 0; i < 5; i++){
        sum2[i] = electic3[i].japanese + electic3[i].math + electic3[i].english;
    }

    for (i = 0; i < 5; i++){
        sum0 += sum2[i];
    }

    //表の枠組みを作成したい
    printf("%6s\t%6s\t%6s\t%6s\t%6s\n", "名前", "国語", "数学", "英語", "合計");

    for (i = 0; i < 5; i++){
        printf("%6s %6d %6d %6d %6d\n", electic3[i].name,
                electic3[i].japanese, electic3[i].math, electic3[i].english, sum2[i]);
    }

    printf("%6s %6.1f %6.1f %6.1f %6.1f\n",
            "平均", (double)sum1[0] / 5, (double)sum1[1] / 5, (double)sum1[2] / 5, (double)sum0 / 5);
    return 0;
}
