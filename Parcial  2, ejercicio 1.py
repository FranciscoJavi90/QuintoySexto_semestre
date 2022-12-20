#  Carlos Fuentes
# 2590-20-9710
N=1000

def hash_truncamiento4(k):
    k2=k//100000
    print(k2)
    cifra1=(k1//100)%1000
    print(cifra1)
    cifra2=k1%100
    print(cifra2)
    cifra3=k2+cifra1+cifra2
    cifra4=cifra3%N
    return cifra4+1

k1=int(input('Digite un muero para saber la clave: '))
print('La clave es: ',hash_truncamiento4(k1))