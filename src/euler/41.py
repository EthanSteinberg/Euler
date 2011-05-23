'''
Created on May 22, 2011

@author: Ethan
'''

from math import sqrt

from functools import reduce

def all_perms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in all_perms(str[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + str[0:1] + perm[i:]


def isPrime(n):
    if n %2 == 0:
        return False
    
    
    for c in range(3,int(sqrt(n)+2),2):
        if n %c == 0:
            return False
        
    return True
    

if __name__ == '__main__':
    
    theMax = 0
    
    yay = [x for x in range(7,0,-1)]
    #print(yay)
    for p in all_perms(yay):
        thePerm = reduce(lambda x,y: x * 10 + y,p)
        #print (thePerm)
        if thePerm > theMax and isPrime(thePerm):
            theMax = thePerm
            
    print(theMax)
    
    print ("None found")