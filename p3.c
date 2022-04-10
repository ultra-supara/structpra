#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//今回は構造体型が2つほしいのでtypedef
typedef struct Data {
    char name[32];
    char tel[32];
} MyDataType, *lpMyDataType;

//標準入力するあれこれをメイン関数から分離させました
int menu() {
    char ret[8];

    printf("------MENU-------\n");
    printf("1: data入力\n");
    printf("2: data表示\n");
    printf("0: 終了\n");
    printf("*****************\n");
    printf("------>");
    //fgetsが何をする関数だったかどういう記述をすればいいか復習
    fgets(ret, sizeof(ret), stdin);

    return atoi(ret);  //charで受け取ったものを数値列に変換する
}

//構造体で定義した名前と電話番号を格納する関数
int meibo_input(lpMyDataType lpData) {
    char name[32];
    char tel[32];

    printf("氏名--");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
    strcpy(lpData->name, name);

    printf("電話番号--");
    fgets(tel, sizeof(tel), stdin);
    tel[strlen(tel) - 1] = '\0';
    strcpy(lpData->tel, tel);

    return 0;
}

//構造体で定義して入力した情報を出力する関数
int meibo_output(lpMyDataType lpData) {
    if(strcmp(lpData -> name, "") == 0) {
        printf("データがありません\n");
        return -1;
    }

    printf("氏名--%s\n", lpData->name);
    printf("電話番号--%s\n", lpData->tel);

    return 0;
}


int main(){
    int selectno, loopend = 0;

    //構造体の宣言と同時に初期化する
    MyDataType mydata = {"", ""};
    lpMyDataType lpMydata = &mydata;

    while(1){
        selectno = menu();
        switch (selectno) {
            case 1:
            meibo_input(lpMydata);
            break;

            case 2:
            meibo_output(lpMydata);
            break;

            default:
            loopend = 1;
            break;
        }
        if(loopend != 0)
        break;
    }
    return 0;
}
