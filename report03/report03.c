#define WIDTH 3939
#define HEIGHT 2786
#define THRESHOLD 128

#include <stdio.h>
#include <stdlib.h>

typedef struct color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} COLOR;

COLOR data1[WIDTH][HEIGHT];
unsigned char data2[WIDTH][HEIGHT] = { 0 };
unsigned char data3[WIDTH][HEIGHT] = { 0 };
unsigned char data4[WIDTH][HEIGHT] = { 0 };
double filter[3][3] = {{ 1, 1, 1 },
						{ 1, 1, 1 },
						{ 1, 1, 1 }};

int main(){
	int i, j, ii, jj;
	double edged;
	FILE *fp;
	FILE *out;
	char header[54];

	fp = fopen("test.bmp", "rb");
	fclose(fp);

	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
		}
	}

	// ひだりはじなところ
	for(j = 0; j < HEIGHT; j++){
	}
	for(i = 1; i < WIDTH - 1; i++){
		// うえはじなところ
		
		// はしでないところ
		for(j = 1; j < HEIGHT - 1; j++){
			edged = 0;
			// 線形フィルタの適用
			for(ii = 0; ii < 3; ii++){
				for(jj = 0; jj < 3; jj++){
				}
			}
			// 私はまるくなる
			// 倒れない　折れない　潰れることもないから
			// 今日も明日も元気
			// だから私　まるくなる
		}
		// したはしなところ

	}
	// みぎはしなところ
	for(j = 0; j < HEIGHT; j++){
	}

	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
		}
	}

	out = fopen("test_out.bmp", "wb");
	fclose(out);

	return 0;
}
