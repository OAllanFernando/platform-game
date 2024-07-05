#include "interface.hpp"

class ImplementacaoSdl : public Interface {
public:
    void apertaTeclas() override;
    void processarEventos() override;
    void criarJogador() override;
    void criarChao() override;
    void criarInimigo() override;
    void criarFundo() override;
    void criarTiro() override;
    void criarPlacar() override;
    void criarVida() override;
    void criaJanela() override;

};