#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
print("-CAMPEONATO DE FUTBOL-")
print("\nPartidos ganados(3 puntos): ")
part_g = int( input())
print("Partidos empatados(1 punto): ")
part_e = int( input())
print("Partidos perdidos(0 puntos): ")
part_p = int( input())
part_g = part_g*3
part_e = part_e*1
part_p = part_p*0
Total_P = part_g + part_e + part_p
print("\nPuntaje total: ", Total_P)