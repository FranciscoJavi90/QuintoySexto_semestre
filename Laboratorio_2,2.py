#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
nombre = input ("¿Cual es tu nombre?: ")
peso = input("¿Cual es tu peso en kg?:  ")
estatura = input("¿Cual es tu estatura en metros?: ")
i_m_c = round(float(peso)/float(estatura)**2,2)
mensaje = str(nombre)+','+"Tu índice de masa corporal es: "+str(i_m_c)
print (mensaje)