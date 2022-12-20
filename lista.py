lista = [9,10,5,4]

print(lista[3])

lista[3]=20

print(lista[3])

#mostramos elemenetos por medio de un ciclo for 
print('Imprimimos lista con for(forma1)')
for i in range (0,4):
    print(lista[i])


#mostramos elemenetos por medio de un ciclo for 
print('Imprimimos lista con for(forma2)')
for i in range (0,len(lista)):
    print(lista[i])

#mostramos elemenetos por medio de un ciclo for 
print('Imprimimos lista con for(forma3)')
for i in lista:
    print(i)

#mostramos elemenetos por medio de un ciclo while 
print('Imprimimos lista con ciclo while')
i=0
while i<4:
    print(lista[i])
    i=i+1