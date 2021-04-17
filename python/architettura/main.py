N = -1

def esercizio(aritmetico=(N, N), loadstore=(N, N), branch=(N, N)):
    CPI_MEDIO = (aritmetico[0] * aritmetico[1] + 
                loadstore[0] * loadstore[1] + 
                branch[0] * branch[1])/100
    print("CPI medio = ", CPI_MEDIO)


#       Si consideri un certo programma con 70% di istruzioni di tipo aritmetico, 10%
#       load/store e 20% branch. Si assuma che le istruzioni aritmetiche eseguano in due
#       cicli, le load/store in sei e i branch in tre. Qual è il CPI medio?

esercizio((70, 2), (10, 6), (6, 3))