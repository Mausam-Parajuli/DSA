
def revString(value):
    stack = []
    return_string = ''
    print(value)
    for i in value:
        stack.append(i)
    
    while stack:
        return_string += stack.pop()
    return return_string

reverse = revString('Himal Bhandari')
print(reverse)