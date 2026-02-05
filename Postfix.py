exp = input("Enter the postfix expression:")
tokenlist = exp.split()
stackList = []

for token in tokenlist:
    if(token.isdigit() or ((token[0]=="-") and token[1:].isdigit())):
        stackList.append(token)
    else:
        op1 = float(stackList.pop())
        op2 = float(stackList.pop())
        operator = token
        if operator == "^":
            result = op2**op1
        elif operator == "/":
            result = op2/op1
        elif operator == "*":
            result = op2*op1
        elif operator == "+":
            result = op2+op1
        elif operator == "-":
            result = op2-op1
        stackList.append(result)
print(f"The solution is :{stackList[-1]}")