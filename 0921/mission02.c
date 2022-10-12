#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct stack_node {
    char data;
    struct stack_node* link;
};

void push(char data);
char pop(void);

struct stack_node* top = NULL;

int main(void)
{
    int count = 0;
    char key;
    do {
        count++;
        printf("%2d ���ڸ� �Է��ϼ��� ", count);
        key = getch();
        push(key);
        printf("%c \n", key);
    } while (key != 27);
    printf("\n\n");
    printf("���� ���� \n\n");
    while (top != NULL) {
        key = pop();
        printf("%c ", key);
    }
    printf("\n");
    return 0;
}

void push(char data)
{
    struct stack_node* new_node;
    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->link = top;
    top = new_node;
}

char pop(void)
{
    struct stack_node* temp;
    char data;
    data = top->data;
    temp = top;
    top = top->link;
    free(temp);
    return data;
}