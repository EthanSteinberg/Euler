'''
Created on May 22, 2011

@author: Ethan
'''

def binaryRep(number):
    x = str()
    
    while (number):
        x = x + str(number%2)
        number = number //2
    
    return x

def isPalidrome(string):
    if string[0] == '0':
        return False
    
    firstHalf = string[:len(string)//2]
    secondHalf = string[len(string) : (len(string)-1)//2 :-1]
    return firstHalf == secondHalf
                             
    

if __name__ == '__main__':
    sum = 0
    for i in range(1,1000000,2):
        if isPalidrome(str(i)) and isPalidrome(binaryRep(i)):
            sum = sum + i
        
    print(sum)