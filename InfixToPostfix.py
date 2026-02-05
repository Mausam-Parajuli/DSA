
exp = input('Enter your infix expression:')
stackList = []
tokenlist = exp.split()
result = ''

for token in tokenlist:
    if token == "(" :
        stackList.append(token)
    elif (token.isalpha() or token.isdigit()):
        result = result + ' ' + token
    elif token == ")":
        while stackList and (stackList[-1] != "("):
            result = result + ' ' + stackList.pop()
        if stackList and stackList[-1] == "(":
            stackList.pop()
    else:
        if token == "^":
            stackList.append(token)
        elif token == "/":
            if stackList and stackList[-1] == "^":
                result = result + ' ' + stackList.pop()
            else:
                stackList.append(token)
        elif token == "*":
            if stackList and stackList[-1] in ['^','/']:
                while stackList and stackList[-1] in ['*','(','+','-']:
                        result = result + ' ' + stackList.pop()
            else:
                stackList.append(token)
        elif token == "+":
            if stackList and stackList in ['^','/','*']:
                while stackList and stackList[-1] in ['(','+','-']:
                        result = result + ' ' + stackList.pop()
            else:
                stackList.append(token)
        elif token == "-":
            if stackList and stackList[-1] in ['^','/','*','+']:
                while stackList and stackList[-1] in ['(','-']:
                    result = result + ' ' + stackList.pop()
            else:
                stackList.append(token)
    
print(f"Infix Expression: {exp}")
print(f"Postfix Expression: {result}")



    