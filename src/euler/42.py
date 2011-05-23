'''
Created on May 22, 2011

@author: Ethan
'''

import sys

def convChar(theThing):
    return ord(theThing) - ord('A') + 1

if __name__ == '__main__':
    
    triangeNums = {(n/2 * (n+1)) for n in range(1,19)}
    
    f = open (sys.argv[1],'r')
    theStr = f.read().replace("\"","").split(",")
    
    numOfTriag = 0
    
    for word in theStr:
        sum = 0
        for char in word:
            sum+= convChar(char)
        
        if sum in triangeNums:
            numOfTriag = numOfTriag + 1
    
    print(numOfTriag)
    print(triangeNums)