#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
from colision_hash import N
N=10
arreglo = [None]*(N+1)
i=0
def hash_modulo(k1):
    return (k1%10)+1
def hash_prueba1(iteracion, indice):
    return (iteracion*iteracion)+indice
def prueba_c(i,indice, clave):
    i=i+1
    nuevoIndice = hash_prueba1(i,indice)
    if len(arreglo) > nuevoIndice:
        if arreglo[nuevoIndice] != None:
            prueba_c(i,indice,clave)
        else:
            arreglo[nuevoIndice]=clave
            i=1
    else:
        i=0
        indice=1
        prueba_c(i,indice,clave)
def inser(clave):
    indice = hash_modulo(clave)
    if(arreglo[indice]!=None):
        prueba_c(i,indice,clave)
    else:    
        arreglo[indice] = clave
inser(25)
inser(43)
inser(56)
inser(35)
inser(54)
inser(13)
inser(80)
inser(104)
inser(55)
print(arreglo)
