class Node():
    def __init__(self, chave):
        self.__pai = None
        self._direito = None
        self._chave = chave
        self._esquerdo = None

    def getChave(self):
        return self._chave
    def setChave(self, value):
        self._chave = value

    def getDireito(self):
        return self._direito

    def setDireito(self, value):
        self._direito = value

    def getEsquerdo(self):
        return self._esquerdo
    def setEsquerdo(self, value):
        self._esquerdo = value

    def getPai(self):
        return self._pai

    def setPai(self, value):
        self._pai = value
class AVL():
    def __init__(self):
        self.__nulo = Node(None)
        self.__nulo.setEsquerdo(self.getNulo())
        self.__nulo.setDireito(self.getNulo())
        self.__nulo.setPai(self.getNulo())
        self.__raiz = self.getNulo()

    def getNulo(self):
        return self.__nulo

    def setNulo(self, valor):
        self.__nulo = valor

    def getRaiz(self):
        return self.__raiz

    def setRaiz(self, valor):
        self.__raiz = valor

    def highest(self, x):
        if x == self.getNulo():
            return -1
        h1 = self.highest(x.getEsquerdo())
        h2 = self.highest(x.getDireito())
        return (1 + max(h1, h2))

    def EmOrdem(self, x,lista):
        if x != self.getNulo():
            self.EmOrdem(x.getEsquerdo(),lista)
            lista.append(x.getChave())
            self.EmOrdem(x.getDireito(),lista)

    def buscar(self, x, k):
        while x != self.getNulo() and k != x.getChave():
            if k < x.getChave():
                x = x.getEsquerdo()
            else:
                x = x.getDireito()
        return x

    def min(imoself, x):
        while x.getEsquerdo() != self.getNulo():
            x = x.getEsquerdo()
        return x

    def maximo(self, x):
        while x.getDireito() != self.getNulo():
            x = x.getDireito()
        return x
    def verificar(self, no):
        return self.highest(no.getEsquerdo()) - self.highest(no.getDireito())

    def transplant(self, nodo):
        while nodo.getPai() != self.getNulo():
            if self.verificar(nodo.getPai()) == 2 and self.verificar(nodo) == 1:
                self.rotacaoDireita(nodo.getPai())
            if self.verificar(nodo.getPai()) == -2 and self.verificar(nodo) == -1:
                self.rotacaoEsquerda(nodo.getPai())
            if self.verificar(nodo.getPai()) == 2 and self.verificar(nodo) == -1:
                self.rotacaoEsquerda(nodo)
                self.rotacaoDireita(nodo.getPai().getPai())
            if self.verificar(nodo.getPai()) == -2 and self.verificar(nodo) == 1:
                self.rotacaoDireita(nodo)
                self.rotacaoEsquerda(nodo.getPai().getPai())
            nodo = nodo.getPai()

    def rotacaoEsquerda(self, x):
        y = x.getDireito()
        x.setDireito(y.getEsquerdo())  
        if y.getEsquerdo() != self.getNulo():
            y.getEsquerdo().setPai(x)
        y.setPai(x.getPai())
        if x.getPai() == self.getNulo():
            y.getEsquerdo().setPai(x)
        y.setPai(x.getPai())  
        if x.getPai() == self.getNulo():
            self.setRaiz(y)
        elif x == x.getPai().getEsquerdo():
            x.getPai().setEsquerdo(y)
        else:
            x.getPai().setDireito(y)
        y.setEsquerdo(x)  
        x.setPai(y)

    def rotacaoDireita(self, x):
        y = x.getEsquerdo()
        x.setEsquerdo(y.getDireito())
        y.getDireito().setPai(x)
        y.setPai(x.getPai())
        if x.getPai() == self.getNulo():
            y.getDireito().setPai(x)
        y.setPai(x.getPai())
        if x.getPai() == self.getNulo():
            self.setRaiz(y)
        elif x == x.getPai().getDireito():
            x.getPai().setDireito(y)
        else:
            x.getPai().setEsquerdo(y)
        y.setDireito(x)
        x.setPai(y)

    def insert(self, dado):
        novo = Node(dado)
        y = self.getNulo()
        x = self.getRaiz()
        while x != self.getNulo():
            y = x
            if novo.getChave() < x.getChave():
                x = x.getEsquerdo()
            else:
                x = x.getDireito()
        novo.setPai(y)
        if y == self.getNulo():
            self.setRaiz(novo)
        elif novo.getChave() < y.getChave():
            y.setEsquerdo(novo)
        else:
            y.setDireito(novo)
        novo.setDireito(self.getNulo())
        novo.setEsquerdo(self.getNulo())
        self.transplant(novo)
    def level(self, nodo):
        if nodo == self.getNulo():
            return -1
        else:
            x = nodo
            level = 1
            while x != self.getRaiz():
                x = x.getPai()
                level += 1
            return level
generos = int(input())
for x in range(generos):
  if x > 0:
    print("")
  avl = AVL()
  while True:
    comandos = input()
    if comandos != "F":
      comandos = comandos.split(" ")
    if comandos[0] == "I":
      avl.insert(int(comandos[1]))
    elif comandos[0] == "N":
      nodo = avl.buscar(avl.getRaiz(),int(comandos[1]))
      print(avl.level(nodo))
    elif comandos[0] == "L":
      limiteInicial, limiteFinal,lista = int(comandos[1]), int(comandos[2]), []
      avl.EmOrdem(avl.getRaiz(), lista)
      if lista != []:
        filmes = filter(lambda x: x >= limiteInicial and x<= limiteFinal, lista)
        string = ""
        for y in list(filmes):
          string += str(y) + " "
        print(string[:-1])
      else:
        print("-1")
    else:
      break