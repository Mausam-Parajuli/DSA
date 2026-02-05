#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define Max 50

struct stack{
    float data[Max];
    int TOS;
};

void push(struct stack *s, float element){
    if(s->TOS == Max - 1) printf("The stack is full.");
    else{
        s->TOS = s->TOS + 1;
        s->data[s->TOS] = element;
    }
}
float pop(struct stack *s)
{
    float element;
    if(s->TOS == -1) printf("The stack is already empty.\n");
    else
    {
        element = s->data[s->TOS];
        s->TOS = s->TOS - 1;
    }
    return element;
}

int main(){
    struct stack s;
    s.TOS = -1;
    char exp[50];
    char *token;
    float solution,num,op1,op2,result;

    printf("Enter your postfix expression:");
    fgets(exp,50,stdin);
    token = strtok(exp , " \n");
    while (token != NULL)
    {   
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            num = atof(token);
            push(&s ,num);
        }
        else{
            op1=pop(&s);
            op2=pop(&s);
            switch (token[0]) {
                case '^':  
                    push(&s,pow(op2, op1));
                    break;

                case '/':  
                    push(&s,op2 / op1);
                    break;

                case '*': 
                    push(&s,op2 * op1);
                    break;

                case '+': 
                    push(&s,op2 + op1);
                    break;

                case '-':  
                    push(&s,op2 - op1);
                    break;

            push(&s, result);
            }
        }
        token = strtok(NULL, " \n");
    }
    solution = pop(&s);
    printf("The solution to the expression is %f",solution);
    
    return 0;
}
