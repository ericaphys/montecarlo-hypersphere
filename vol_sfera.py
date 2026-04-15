import scipy as sc
import numpy as np
import math 

#numeri random tra -1 e 1
def random(m):
    x=np.random.uniform(-1,1,(m))
    return x

def main():
    N=1000000
    M=int(input("Inserire dimensione dello spazio:\n"))
    omega=pow(2,M)
    gamma=sc.special.gamma((M/2)+1)
    Vol_t=pow(math.pi, M/2)/gamma
    print("Valore di riferimento:")
    print(Vol_t)

    media=0
    funz=[]
    for i in range(N):
        x=random(M)
        p=np.dot(x,x)
        if(p<=1):
            media+=1
            funz.append(1)
        else:
            funz.append(0)
    media=media/N
    Vol=omega*media
    print("Valore stimato:")
    print(Vol)
    
    somma=0
    somma2=0
    for j in range(len(funz)):
        somma+=pow(funz[j]-media,2)
        somma2+=pow(funz[j],2)
        
    #somma2=somma2/N 
    #var=somma2-media**2
    var=somma/N
    
    sigma=np.sqrt(var/N)
    print(sigma)
    #print(1/np.sqrt(N))

if __name__=='__main__':
    main()