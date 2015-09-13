/*
 * equeen.c
 *
 * 本程序试图解决八皇后问题：在 8x8 的棋盘上，8位皇后不能在同一行、同一列、
 * 同一对角线上，求有多少种摆法。
 */
#include <stdio.h>

#define NQUEEN 8

typedef struct _queen Queen;
struct _queen {
	int x;
	int y;
};

Queen queen[NQUEEN+1];
int nmethods = 0;

void place_queens(int num_queen);

int
main(int argc, char *argv[])
{
	place_queens(1);
	printf("%d\n", nmethods);

	return 0;
}

int
abs(int n)
{
	return (n >= 0 ? n : -n);
}

int
is_on_same_row(Queen *a, Queen *b)
{
	return (a->y == b->y);
}

int
is_on_same_column(Queen *a, Queen *b)
{
	return (a->x == b->x);
}

int
is_on_same_diagonal(Queen *a, Queen *b)
{
	int up, down;
	down = ((a->x + a->y) == (b->x + b->y));
	up = (abs(b->x - a->x) == abs(b->y - a->y));

	return (up || down);
}

int
is_corrupt(Queen *a, Queen *b)
{
	return (is_on_same_row(a, b)
					|| is_on_same_column(a, b)
					|| is_on_same_diagonal(a, b)
					);
}

void
print(void)
{
	int line, x;
	int i;
	for (line = NQUEEN; line >= 1; line--) {	/* 对于每行 */
		for (x = 1; x <= NQUEEN; x++)	/* 找出该行的皇后处于哪一列 */
			if (queen[x].y == line)
				break;
		for (i = 1; i < x; i++)
			printf("口");
		printf("山");
		for (i = x+1; i <= NQUEEN; i++)
			printf("口");

		putchar('\n');
	}
	putchar('\n');
}

void
place_queens(int num_queen)
{
	int j; /* 遍历同一列 */
	int k; /* 在比较时遍历之前的皇后 */

	queen[num_queen].x = num_queen;

	if (num_queen == NQUEEN) {	/* 最后一个皇后 */
		for (j = 1; j <= NQUEEN; j++) {
			queen[num_queen].y = j;
			for (k = 1; k < num_queen; k++)	{/* 开始验证是否同行列斜 */
				if (is_corrupt(&queen[k], &queen[num_queen]))
					break;
			}
			if (k == num_queen-1) {
				nmethods++;
				print();
			}
		}
	} else if (num_queen == 1) {	/* 第一个皇后 */
		for (j = 1; j <= NQUEEN; j++) {
			queen[num_queen].y = j;
			place_queens(2);
		}
	} else {	/* 中间的皇后 */
		for (j = 1; j <= NQUEEN; j++) {
			queen[num_queen].y = j;
			for (k = 1; k < num_queen; k++) {
				if (is_corrupt(&queen[k], &queen[num_queen]))
					break;
			}
			if (k == num_queen-1)
				place_queens(num_queen+1);
		}
	}
}
