#include <stdio.h>
int main()
{
	char string[20];
	char c;
	printf("문자열 입력 > ");
	scanf("%s", string);
	printf("문자 입력 > ");
	getchar(); //getchar(); 를 추가하는 걸로도 가능
	scanf(" %c", &c); //%c 앞에 공백을 추가하면 white space를 구분자로 인식한다.
	printf("%s\n", string);
	printf("!!%c!!\n", c);
	
	return 0;
}
