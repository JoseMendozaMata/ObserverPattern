#include <iostream>

using namespace std;

class Figura {
  public:
    Figura() {
      id = acumulador++;
    }
    virtual void dibuja() = 0;
  protected:
    int id;
    static int acumulador;
};

int Figura::acumulador = 0;

class Circulo : public Figura {
  public:
    void dibuja() {
      cout << "circulo " << id << ": dibuja circulo" << endl;
    }
};
class Cuadrado : public Figura {
  public:
    void dibuja() {
      cout << "cuadrado " << id << ": dibuja cuadrado" << endl;
    }
};
class Elipse : public Figura {
  public:
    void dibuja() {
      cout << "elipse " << id << ": dibuja elipse" << endl;
    }
};
class Rectangulo : public Figura {
  public:
    void dibuja() {
      cout << "rectangulo " << id << ": dibuja rectangulo" << endl;
    }
};

class Factory {
  public:
    virtual Figura* crearInstanciaCurva() = 0;
    virtual Figura* crearInstanciaRecta() = 0;
};

class FabricaFigurasSimples : public Factory {
  public:
    Figura* crearInstanciaCurva() {
      return new Circulo;
    }
    Figura* crearInstanciaRecta() {
      return new Cuadrado;
    }
};
class FabricaFigurasRobustas : public Factory {
  public:
    Figura* crearInstanciaCurva()   {
      return new Elipse;
    }
    Figura* crearInstanciaRecta() {
      return new Rectangulo;
    }
};

int main() {
  Factory* factorySimple = new FabricaFigurasSimples;
  Factory* factoryRobust = new FabricaFigurasRobustas;
  Figura* figuras[3];

  figuras[0] = factoryRobust->crearInstanciaCurva();   // figuras[0] = new Elipse;
  figuras[1] = factorySimple->crearInstanciaRecta(); // figuras[1] = new Rectangulo;
  figuras[2] = factoryRobust->crearInstanciaCurva();   // figuras[2] = new Elipse;

  for (int i=0; i < 3; i++) {
    figuras[i]->dibuja();
  }
}