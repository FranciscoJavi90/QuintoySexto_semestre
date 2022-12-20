#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
import numpy as np
N = 6
INF=999
mtz = np.array([
        [0,     5,     INF,   INF,   8,     INF ],
        [INF,   0,     INF,   3,     5,     4   ],
        [2,     INF,   0,     3,     INF,   INF ],
        [INF,   INF,   INF,   0,     5,     7   ],
        [INF,   INF,   6,     INF,   0,     INF ],
        [INF,   INF,   INF,   INF,   INF,   0   ]
])
for c in range(N):          
    for a in range(0,N):
        for b in range(0,N):
            if(mtz[a,c] + mtz[c,b] < mtz[a,b]):
                mtz[a,b] = mtz[a,c] + mtz[c,b]

print("---TRABAJAR CON EL SIGUIENTE GRAFO---")
print("-SELECCIONE UN CAMINO A RECORRER DENTRO DE DOS NODOS-")
print("-PUEDE ESCOGER NODO a, b, c, d, e, f.-")
print("----------MATRIZ PROGRAMADA----------")
print(mtz)
print("Ingrese Primer nodo: ")
graf_1 = input()
print("Ingrese Segundo nodo: ")
graf_2 = input()
a=0
b=0
c=0
d=0
f=0
if graf_1 == 'a':
    a = 0
if graf_1 == 'b':
    a = 1
if graf_1 == 'c':
    a = 2
if graf_1 == 'd':
    a = 3
if graf_1 == 'e':
    a = 4
if graf_1 == 'f':
    a = 5
if graf_2 == 'a':
    b = 0
if graf_2 == 'b':
    b = 1
if graf_2 == 'c':
    b = 2
if graf_2 == 'd':
    b = 3
if graf_2 == 'e':
    b = 4
if graf_2 == 'f':
    b = 5

print("Distancia entre cada nodo: ")
if (mtz[a,b] == INF):
    print("En los vertices no se encontró opciones a camino.")
else:
    print(mtz[a,b],"DISTANCIA entre cada uno, (se elige el más corto).")
