#include <stdio.h>
int main()
{
	char string[20];
	char c;
	printf("���ڿ� �Է� > ");
	scanf("%s", string);
	printf("���� �Է� > ");
	getchar(); //getchar(); �� �߰��ϴ� �ɷε� ����
	scanf(" %c", &c); //%c �տ� ������ �߰��ϸ� white space�� �����ڷ� �ν��Ѵ�.
	printf("%s\n", string);
	printf("!!%c!!\n", c);
	
	return 0;
}
