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

  Factory* factory = new FabricaFigurasRobustas;
  
  Figura* figuras[4];

  figuras[0] = factory->crearInstanciaCurva();   // figuras[0] = new Elipse;

  factory = new FabricaFigurasSimples;

  figuras[1] = factory->crearInstanciaRecta(); // figuras[1] = new Cuadrado;

  factory = new FabricaFigurasSimples;

  figuras[2] = factory->crearInstanciaCurva();   // figuras[2] = new Circulo;

  factory = new FabricaFigurasRobustas;

  figuras[3] = factory->crearInstanciaRecta();   // figuras[2] = new Rectangulo;

  for (int i=0; i < 4; i++) {
    figuras[i]->dibuja();
  }
}