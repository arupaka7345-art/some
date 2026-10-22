#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////

typedef struct
{
    int no;
    char namae[20];
    int tensu;
} greade;

typedef struct
{
    greade rec;       // 成績

    int l;            // 長さ（行数）

    int in;           // 入力

    int pwr;          // 終了の可否
} ctrl;

//////////////////////////////////////////////////////////////////////

int fnew(ctrl *);     // 新規作成

int menu(void);     　// コマンド表示と入力
int show(ctrl);       // レコード表示
int add(ctrl *);      // 追加
int renew(ctrl *);    // 更新
int del(ctrl *);        // 削除（notリユース）

//////////////////////////////////////////////////////////////////////

int main(void)
{
    ctrl com;
    com.pwr = 1;

    fnew(&com);
    
    do
    {
        com.in = menu();

        switch(com.in)
        {
            case 1:
                show(com);
                break;
            
            case 2:
                add(&com);
                break;

            case 3:
                renew(%com);
                break;

            case 4:
                del(&com);
                break;
            
            case 9:  
                com.pwr = 0;
                break;

            default:
                printf("[ERROR]: 無効なID\n");
                break;
        } printf("\n*********************\n\n");
    } while(com.pwr);

    printf("プログラムを終了...\n");
    
    return 0;
}

//////////////////////////////////////////////////////////////////////

int fnew(ctrl *con)
{
    FILE *fp = fopen("seiseki.txt", "r");

    if(!fp)
    {
        printf("[System]: 新しいファイル\n");
        fp = fopen("seiseki.txt", "w");
        freopen("seiseki.txt", "r", fp);
    } fseek(fp, 0, SEEK_SET);
    
    con->l = 0;
    while(fgetc(fp) != EOF)
        fseek(fp, ++con->l * 28L, SEEK_SET);
    
    fclose(fp);

    return 0;
}

//////////////////////////////////////////////////////////////////////

int menu(void)
{
    int id;

    printf("***** main menu *****\n");
    printf("1.list\n");
    printf("2.add\n");
    printf("3.update\n");
    printf("4.delete\n");
    printf("9.end\n");

    printf("\n[System]: コマンド -> ");
    scanf("%d", &id);

    return id;
}

int show(ctrl con)
{
    FILE *fp = fopen("seiseki.txt", "r");

    if(!fp)
    {
        printf("[ERROR]: ファイルを開けません\n");
        return 1;
    } printf("\n");
    for(int i = 0; i < con.l; i++)
    {
        fseek(fp, i * 28L, SEEK_SET);
        fscanf(fp, "%d %s %d", &con.rec.no, con.rec.namae, &con.rec.tensu);

        if(strcmp("[DELETED]", con.rec.namae))
            printf("%d %s %d\n", con.rec.no, con.rec.namae, con.rec.tensu);
    } fclose(fp);

    return 0;
}

int add(ctrl *con)
{
    FILE *fp = fopen("seiseki.txt", "a");

    if(!fp)
    {
        printf("[ERROR]: ファイルを開けません\n");
        return 1;
    } printf("[System]: データ([name] [score]) -> ");
    scanf("%s %d", con->rec.namae, &con->rec.tensu);

    fprintf(fp, "%3d%20s%4d\n", ++con->l, con->rec.namae, con->rec.tensu);
    
    fclose(fp);

    return 0;
}

int renew(ctrl *con)
{
    FILE *fp = fopen("seiseki.txt", "r+");

    if(!fp)
    {
        printf("[ERROR]: ファイルを開けません\n");
        return 1;
    } printf("[System]: レコード番号 -> ");
    scanf("%d", &con->rec.no);

    if(con->rec.no <= con->l)
    {
        printf("[System]: 新しいデータ([name] [score]) -> ");
        scanf("%s %d", con->rec.namae, &con->rec.tensu);

        fseek(fp, (con.rec.no - 1) * 28L, SEEK_SET);
        fprintf(fp, "%3d%20s%4d\n", con->rec.no, con->rec.namae, con->rec.tensu);
    } else 
        printf("[ERROR]: 無効な番号\n");
    
    fclose(fp);
    
    return 0;
}

int del(ctrl *con)
{
    FILE *fp = fopen("seiseki.txt", "r+");
  
    if(!fp)
    {
        printf("[ERROR]: ファイルを開けません\n");
        return 1;
    } printf("[System]: レコード番号 -> ");
    scanf("%d", &con->in);

    if(con->l < con->in)
        printf("[ERROR]: 無効な番号\n");
    else
    {
        fseek(fp, (con->in - 1) * 28L + 3L, SEEK_SET);
        fprintf(fp, " [DELETED]          ");
    } fclose(fp);

    return 0;
}
