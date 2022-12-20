#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N = 10
arreglo = [None]*(N+1) #Arreglo de 11 elementos inicializados con cero

def hash_modulo(k):
    return k%N+1

def prueba_lineal(valor):
    clave = 0
    for i in range(0,len(str(valor))):
        clave +=ord(str(valor[i]))
    return clave % (N+1)
    

def insertar(valor):
    indice = prueba_lineal(valor)
    if arreglo[indice] is None:
        arreglo[indice] = valor
    
#Insertar los datos en el arreglo
insertar(25)
insertar(75)
insertar(65)
insertar(35)

print(arreglo)