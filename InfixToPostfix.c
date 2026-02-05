#include <stdio.h>
#define MAX 20

struct stack {
    int TOP;
    char data[MAX];
};

void push(struct stack *,char);
char pop(struct stack *);
int priority(char);

int main()
{
    struct stack temp ={-1};
    struct stack output ={-1};
    char infix[MAX];
    char gbg, operator;
    int i = 0;

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    while (infix[i] != '\n') 
    {
        switch (infix[i]) 
        {
            case '(':
                push(&temp, '(');
                break;

            case ')':
                while (temp.data[temp.TOP] != '(')
                {
                    gbg = pop(&temp);
                    push(&output, gbg);
                }
                gbg = pop(&temp);
                break;
            
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            operator = infix[i];
                while(priority(temp.data[temp.TOP]) >= priority(operator))
                {
                    gbg = pop(&temp);
                    push(&output, gbg);
                }
                push(&temp, operator);
                break;

            default:
                push(&output, infix[i]);
                break;
        }
        i++;
    } 
    while (temp.TOP != -1) 
    {
        gbg = pop(&temp);
        push(&output, gbg);
    }
    printf("Postfix expression is %s ",output.data);
    printf("\n");
    return 0;
}

void push(struct stack *s,char element)
{
    s->data[++s->TOP] = element;
}
char pop(struct stack *s)
{
    return s->data[s->TOP--];
}
int priority(char opr)
{
    if(opr == '^')
        return 3;
    if(opr == '*' || opr == '/')
        return 2;
    if(opr == '+' || opr == '-')
        return 1;
    if(opr == '(')
        return 0;
}