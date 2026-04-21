#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} bool;

int main()
{
	printf("部屋数："); scanf("%", &tr);

	while(cr < tr)
	{
		
	}

	return 0;
}

/*
 マップを生成したい（改変とかはともかく）
・準備
　未だ未定

・入力
　部屋の個数入力したい

・生成
　ぶっちゃけ右往左往しまくるから時間は気にしない
　・乱数
　　ぶっちゃけ疑似でおｋ
　　rand() % 6とかでいいかな

　・操作
　　0-5の範囲
　　　0.右
　　　1.左
　　　2.上
　　　3.下
　　　4.ロックの切り替え
　　　5.一つ戻る（スタック使わなきゃなぁ）

　　・スタック
```
typedef unsigned char uint8_t;

uint8_t stack[256] = {0};
uint8_t sp = 0;

bool push(uint8_t v)
{	stack[sp++] = v;

	return true;
}

uint8_t pop(void)
{	return stack[--sp];
}
```

*/
