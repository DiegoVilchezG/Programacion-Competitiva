from itertools import combinations

def combinacion(cadena):
	combinaciones = []

	for i in range(0,len(cadena)):
		combinaciones.append(cadena[i])
	for i in range(1,len(cadena)):
		for j in combinations(cadena,i+1):
			combinaciones.append(j)

	return combinaciones

t = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
print(combinacion(t))
