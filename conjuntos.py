def leer_conjunto():
    entrada = input("Ingresa los números separados por coma: ")
    numeros = entrada.split(",")
    conjunto = set(map(int, numeros))
    return conjunto

def operacion_interseccion(conjunto_a, conjunto_b):
    resultado = conjunto_a & conjunto_b
    print(f"Intersección (A ∩ B): {resultado}")

def operacion_union(conjunto_a, conjunto_b):
    resultado = conjunto_a | conjunto_b
    print(f"Unión (A ∪ B): {resultado}")

def operacion_diferencia(conjunto_a, conjunto_b):
    resultado = conjunto_a - conjunto_b
    print(f"Diferencia (A - B): {resultado}")

def operacion_diferencia2(conjunto_a, conjunto_b):
    resultado = conjunto_b - conjunto_a
    print(f"Diferencia (A - B): {resultado}")

def operacion_diferencia_simetrica(conjunto_a, conjunto_b):
    resultado = (conjunto_a - conjunto_b) | (conjunto_b - conjunto_a)
    print(f"Diferencia (A - B): {resultado}")

def calcular_cardinalidad_a(conjunto_a):
    cardinalidad = len(conjunto_a)
    print(f"La cardinalidad del conjunto es: {cardinalidad}")

def calcular_cardinalidad_b(conjunto_b):
    cardinalidad = len(conjunto_b)
    print(f"La cardinalidad del conjunto es: {cardinalidad}")

def producto_cartesiano_axb(conjunto_a, conjunto_b):
    resultado = []
    for elemento1 in conjunto_a:
        for elemento2 in conjunto_b:
            resultado.append((elemento1, elemento2))
    print(f"El producto cartesiano del conjunto es: {resultado}")

def producto_cartesiano_bxa(conjunto_a, conjunto_b):
    resultado = []
    for elemento1 in conjunto_b:
        for elemento2 in conjunto_a:
            resultado.append((elemento1, elemento2))
    print(f"El producto cartesiano del conjunto es: {resultado}")    

def producto_cartesiano_axa(conjunto_a):
    resultado = []
    for elemento1 in conjunto_a:
        for elemento2 in conjunto_a:
            resultado.append((elemento1, elemento2))
    print(f"El producto cartesiano del conjunto es: {resultado}")

def producto_cartesiano_bxb(conjunto_b):
    resultado = []
    for elemento1 in conjunto_b:
        for elemento2 in conjunto_b:
            resultado.append((elemento1, elemento2))
    print(f"El producto cartesiano del conjunto es: {resultado}")


if __name__ == "__main__":
    print("Calculadora de Conjuntos")
    conjunto_a = leer_conjunto()
    conjunto_b = leer_conjunto()

    print("\nOperaciones disponibles:")
    print("1. Intersección (A ∩ B)")
    print("2. Unión (A ∪ B)")
    print("3. Diferencia (A - B)")
    print("4. Diferencia (B - A)")
    print("5. Diferencia simétrica (A∆B)")
    print("6. Complemento(A)")
    print("7. Complemento (B)")
    print("8. Producto cartesiano (A x B)")
    print("9. Producto cartesiano (B x A)")
    print("10. Producto cartesiano (A x A)")
    print("11. Producto cartesiano (B x B)")
    print("12. Conjunto potencia P(A)")
    print("13. Conjunto potencia P(B)")
    print("14. Cardinalidad (A)")
    print("15. Cardinalidad (B)")
    


    opcion = int(input("Selecciona una operación (1-6): "))

    if opcion == 1:
        operacion_interseccion(conjunto_a, conjunto_b)
    elif opcion == 2:
        operacion_union(conjunto_a, conjunto_b)
    elif opcion == 3:
        operacion_diferencia(conjunto_a, conjunto_b)
    elif opcion == 4:
        operacion_diferencia2(conjunto_a, conjunto_b)
    elif opcion == 5:
        operacion_diferencia_simetrica(conjunto_a, conjunto_b)
    elif opcion == 6:
        #complemento (A)
    elif opcion == 7:
        #complemento (B)
    elif opcion == 8:
        producto_cartesiano_axb(conjunto_a, conjunto_b)
    elif opcion == 9:
        producto_cartesiano_bxa(conjunto_a, conjunto_b)
    elif opcion == 10:
        producto_cartesiano_axa(conjunto_a)
    elif opcion == 11:
        producto_cartesiano_bxb(conjunto_b)
    elif opcion == 12:
        #conjunto potencia P(A)
    elif opcion == 13:
        #conjunto potencia P(B)
    elif opcion == 14:
        calcular_cardinalidad_a(conjunto_a)
    elif opcion == 15:
        calcular_cardinalidad_b(conjunto_b)

    else:
        print("Opción no válida. Inténtalo de nuevo.")
