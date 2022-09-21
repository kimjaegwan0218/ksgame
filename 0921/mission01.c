#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

int calc_frequency(int octave, int inx);

int main(void)
{
	printf("1부터 8까지 숫자 키를 누르면\n");
	printf("각 음의 소리가 출력됩니다.\n\n");
	printf("1:도 2:레 3:미 4:파 5:솔 6:라 7:시 8:도\n");
	printf("프로그램 종료는 Esc키 \n");
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8], code, i;
	int abc[24] = { 7, 7, 9, 9, 7, 7, 4, 7, 7, 4, 4, 2, 7, 7, 9, 9, 7, 7, 4, 7, 4, 2, 4, 0 };
	for (i = 0; i < sizeof(abc) / sizeof(int); i++){
		Beep(calc_frequency(4,(abc[i])), 500);
	}
	
	return 0;
} 

int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
