'''
Created on May 22, 2011

@author: Ethan
'''


if __name__ == '__main__':
    
    
    
    print("Project euler")
    
    theMax = 0
    for i in range(1,10000):
        
        cur = str()
        used = [False for _ in range(1,10)]
        for b in range (1,10):
            cur+= str(i*b)
            for char in str(i*b): 
                #print(int(char)-1)
                if (int(char) == 0) or ((used[int(char)-1]) == True):
                    #print("The char was bad",char,cur,used)
                    break 
                
                used[int(char)-1] = True
                
            
            else:
                if all(used):
                    print(cur,i,b)
                    theMax= max(theMax,int(cur))
    print (theMax)
                    
                    
            