def factorial():
    def tailfact(n,a):
        if n == 0:
            return a
        else:
            return tailfact(n-1,a*n)
    n = int(input("Enter the no you want factorial of:\n"))
    factorial = tailfact(n,1)
    print(f'The factorial is {factorial}.')

def gcd():
    def hcf(a,b):
        if b==0:
            return a
        else:
            return hcf(b,a%b)
    a,b = int(input('Enter the first number:')),int(input('Enter the second number:'))
    if b>a:
        result = hcf(a,b)
    else:
        result = hcf(b,a)
    print(f'The HCF is: {result}')

def fibonacci():
    def fibo():
        max = 100
        table = []
        for i in range(max):
            table.append(0)
        def withOutMemo(n):
            if n==1 or n==2:
                return 1
            else:
                return withOutMemo(n-1) + withOutMemo(n-2)
        def withMemo(n):
            if n==1 or n==2:
                return 1
            if table[n] != 0:
                return table[n]
            table[n] = withMemo(n-1) + withMemo(n-2)
            return table[n]
        term = int(input('Enter the nth term:'))
        choice = int(input('Enter 1.For Without Memo 2.For With Memo\n'))
        if choice == 1:
            result = withOutMemo(term)
        else:
            result = withMemo(term)
        print(f'The {term}th fibonacci term is {result}')
    fibo()
        
def vietnam():
    moves = 0
    src,tmp,dst = 'A','B','C'
    def toh(n,src,dst,tmp):
        nonlocal moves
        if n==1:
            print(f'Move disc {n} from {src} to {dst}')
            moves+=1
        else:
            toh(n-1,src,tmp,dst)
            print(f'Move diec {n} from {src} to {dst}')
            toh(n-1,tmp,dst,src)
            moves+=1
    n = int(input('Enter the no of discs:'))
    toh(n,src,dst,tmp)
    print(f'Process complete in {moves} moves.')

i = 1
while i!=0:
    def main():
        global i
        a = input("Enter your option:\n 1.factorial \n 2.gcd \n 3.fibonacci \n 4.toh \n 5.Enter any key to exit \n")
        if a == '1':
            factorial()
        elif a=='2':
            gcd()
        elif a=='3':
            fibonacci()
        elif a=='4':
            vietnam()
        else:
            i = 0
    main()




#factorial()
#gcd()
#fibonacci()
#vietnam()
    
