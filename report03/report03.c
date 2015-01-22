#define WIDTH 640
#define HEIGHT 480
#define THRESHOLD 75

#include <stdio.h>
#include <stdlib.h>

typedef struct color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} COLOR;

// �J���[�f�[�^
COLOR data1[WIDTH][HEIGHT];
// �O���[�X�P�[���f�[�^
unsigned char data2[WIDTH][HEIGHT] = { 0 };
// �G�b�W���o�f�[�^
unsigned char data3[WIDTH][HEIGHT] = { 0 };
// 2�l���f�[�^
unsigned char data4[WIDTH][HEIGHT] = { 0 };
// ���`�t�B���^
double filter[3][3] = {{ 1, 1, 1 },
						{ 1, -8, 1 },
						{ 1, 1, 1 }};

int main(){
	int i, j, ii, jj;
	double edged;
	FILE *input;
	FILE *output;
	char header[54];

	// �J���[�f�[�^�ƃt�@�C���w�b�_�̓ǂݍ���
	input = fopen("test.bmp", "rb");
	fread(header, 1, 54, input);
	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
			data1[i][j].b = getc(input);
			data1[i][j].g = getc(input);
			data1[i][j].r = getc(input);
		}
	}
	fclose(input);

	// ���f�[�^����O���[�X�P�[���f�[�^�ւ̕ϊ�
	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
			data2[i][j] = (data1[i][j].r + data1[i][j].g + data1[i][j].b) / 3;
		}
	}

	// �O���[�X�P�[���f�[�^����G�b�W�𒊏o
	// ���[�̉�f�l����
	for(j = 0; j < HEIGHT; j++){
		data3[0][j] = data2[0][j];
	}
	// ��[�̉�f�l����
	for(i = 1; i < WIDTH - 1; i++){
		data3[i][0] = data2[i][0];
		// �[�łȂ���f�l�̌���
		for(j = 1; j < HEIGHT - 1; j++){
			edged = 0;
			// ���`�t�B���^�̓K�p
			for(ii = 0; ii < 3; ii++){
				for(jj = 0; jj < 3; jj++){
					edged += data2[i + ii - 1][j + jj - 1] * filter[ii][jj];
				}
			}
			// �l�ۂ�
			if(edged < 0)	edged = 0;
			else if(edged > 255)	edged = 255;
			data3[i][j] = edged;
		}
		// ���[�̉�f�l����
		data3[i][HEIGHT - 1] = data2[i][HEIGHT - 1];
	}
	// �E�[�̉�f�l����
	for(j = 0; j < HEIGHT; j++){
		data3[WIDTH - 1][j] = data2[WIDTH - 1][j];
	}

	// �G�b�W���o�f�[�^���l���f�[�^�ɕϊ�
	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
			data4[i][j] = data3[i][j] < THRESHOLD ? 255 : 0;
		}
	}

	// ��l���f�[�^�ƃt�@�C���w�b�_�̏����o��
	output = fopen("test_out.bmp", "wb");
	fwrite(header, 1, 54, output);
	for(j = HEIGHT - 1; j >= 0; j--){
		for(i = 0; i < WIDTH; i++){
			fputc(data4[i][j], output);
			fputc(data4[i][j], output);
			fputc(data4[i][j], output);
		}
	}
	fclose(output);

	return 0;
}
