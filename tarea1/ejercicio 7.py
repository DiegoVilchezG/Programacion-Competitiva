from itertools import permutations

def permutacion(cadena):
	permutaciones = []
	permutaciones.append(list(permutations(cadena)))

	return permutaciones

t = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
print(permutacion(t))
