import numpy as np

#definimos el tamaño de la matriz
N = 6
#definimos la matriz de costos
matriz = np.array([
        [0,     5,     999,   999,   8,     999 ],
        [999,   0,     999,   3,     5,     4   ],
        [2,     999,   0,     3,     999,   999 ],
        [999,   999,   999,   0,     5,     7   ],
        [999,   999,   6,     999,   0,     999 ],
        [999,   999,   999,   999,   999,   0   ]
])

for k in range(N):          #range comienza desde 0 hasta N
    for i in range(0,N):
        for j in range(0,N):
            if(matriz[i,k] + matriz[k,j] < matriz[i,j]):
                matriz[i,j] = matriz[i,k] + matriz[k,j]

print('matriz de caminos: ')
print(matriz)


print("ingresa nodo 1: ")
can = input()
print("ingresa nodo 2: ")
can2 = input()
a=0
b=0

d=0
if can == 'a':
    i = 0
if can == 'b':
    i = 1
if can == 'c':
    i = 2
if can == 'd':
    i = 3
if can == 'e':
    i = 4
if can == 'f':
    i = 5


if can2 == 'a':
    j = 0
if can2 == 'b':
    j = 1
if can2 == 'c':
    j = 2
if can2 == 'd':
    j = 3
if can2 == 'e':
    j = 4
if can2 == 'f':
    j = 5


print(matriz[i,j])