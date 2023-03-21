
coloring = {}

#Anzahl der Zahlen angeben -> CNF wird generiert
def inputToDemacs(countTo):

    counter = 0
    for i in range(1, countTo):
        for j in range(i+1, countTo):
            summe = i + j
            if summe < countTo+1:
                #print(f"{i} + {j} = {summe}".format(i=i, j=j, summe=summe))
                print(f"{i} {j} {summe} 0".format(i=i, j=j, summe=summe))
                print(f"-{i} -{j} -{summe} 0".format(i=i, j=j, summe=summe))
                counter += 2

    print(f"p cnf {countTo} {counter}".format(countTo=countTo, counter=counter))


#generiert den Farbcode für die jeweilige Zahl, je nach signum
def inputToDict(src):
    for num in src:
        if num > 0:
            coloring.update({abs(num): '(R)'})
        else:
            coloring.update({abs(num): '(B)'})
    print(coloring)


#gib Liste Lösungen des SAT Solvers an und erhalte den Color Code inklusive aller Rechnungen
def demacsToNatural(src):
    length = len(src)

    inputToDict(src)

    for i in range(1, length):
        for j in range(i+1, length):
            summe = i + j

            if summe < length+1:
                if coloring[i] == coloring[j] and coloring[j] == coloring[summe]:
                    print("ERROR!")

                else:
                    print("{i}{Vali} + {j}{Valj} = {summe}{Valsumme}".format(i=i, Vali = coloring[i], j=j, Valj = coloring[j], summe=summe,Valsumme = coloring[summe]))

#EXAMPE WITH NUMBERS 1-8
#inputToDemacs(8)
#demacsToNatural((-1, -2, 3, -4, 5, 6, 7, -8))