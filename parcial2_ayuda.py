N=1000

def hash_truncamiento(k):
    k2=k//100000
    print(k2)
    digitos1=(k1//100)%1000
    print(digitos1)
    digitos2=k1%100
    print(digitos2)
    digitos3=k2+digitos1+digitos2
    digitos4=digitos3%N
    return digitos4+1

k1=3825662
print('Indice para la clave es: ',hash_truncamiento(k1))
k2=33598192
print('Indice para la clave es: ',hash_truncamiento(k2))
k3=26901527
print('Indice para la clave es: ',hash_truncamiento(k3))
