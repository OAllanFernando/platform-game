// corpo.hpp

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Corpo {
public:
    int getVida() const { return vida; }
    int getPontos() const { return pontos; }


    void setVida(int newVida) { vida = newVida; }
    void setPontos(int newPontos) { pontos = newPontos; }

    void addVida(int addVida) { vida += addVida; }

private:
    int vida = 100;
    int pontos = 0;

};

#endif