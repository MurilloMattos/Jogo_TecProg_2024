#include "Jogo.h"
//#include "Jogador.h"
//#include "Fase.h"
#include "Menu.h"
using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{
    Ger_Graf = Ente::getpGG();
    //jogador_2.setar_Dois_Jogadores(true);
    //fase1 = new Fase_1();
    //jogador_1 = new Jogador();
    //jogador_1.setpGG(Ger_Graf);
    //fase1->Setar_Jogadores_Colisoes(jogador_1, nullptr);
    m = new Menu();
    //m->setpGG(Ger_Graf);
    m->set_pJog(this);
    //Ger_Graf = m->getpGG();
    //fase1->get_Lista_Entidades()->Incluir(static_cast<Entidade*>(&jogador_1));

    incluirEntes((Ente*)m);
    //incluirEntes((Ente*)fase1);

    //incluirEntes((Ente*)jogador_1);
    //fase1.Setar_Jogadores_Colisoes(&jogador_1, &jogador_2);
}
Jogo::~Jogo()
{
	Ger_Graf = NULL;
}
sf::RenderWindow * Jogo::getJanela(){ return (Ger_Graf->getJanela());}
void Jogo::Executar()
{
    //int i = 0;
    //tempo_principal.restart();
    //tempo.getElapsedTime().asSeconds();
    while (Ger_Graf->getJanela()->isOpen())
    {
        sf::Event evento;

        Ger_Graf->getJanela()->setFramerateLimit(60);

        //tempo.restart();
	
	while (Ger_Graf->getJanela()->pollEvent(evento))
        {
                if (evento.type == sf::Event::Closed) {
                    Ger_Graf->getJanela()->close();
                }
        }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
           // deve ser modificado para encaixar o menu de pause.
	   ((Menu*)entes[0])->set_emMenu(true);
	}
        Ger_Graf->getJanela()->clear();
	if(((Menu*)entes[0])->get_emMenu()){
		entes[0]->Executar();
		//Ger_Graf->getJanela()->setView(m->getCamera());	
	}else{
		Atualiza();
	}
	//Ger_Graf->getJanela()->clear();
        //std::cout << i << std::endl;
        //i++;
        //std::cout << tempo_principal.getElapsedTime().asSeconds(); //<< std::endl;
        //tempo.restart();
        //Atualiza();
    	//jogador_2.Executar();
    	//fase1.Executar();
   	//Atualiza_Camera();
        Ger_Graf->getJanela()->display();

        /*if(fase1->get_Ganhou()) {
            Ger_Graf->getJanela()->close();
        }*/
    } 	
}
void Jogo::Atualiza()
{	
    percorreEntes();    
    
    //fase1->Executar(); // executa o jgo no iterador vigente fase1 fase2.. ditada por menu
    //Fase_1 *f = static_cast<Fase_1*>(entes[2]);
    //f->Setar_Jogadores_Colisoes(jogador_1, nullptr);
    //entes[2]->Executar(); 
    //jogador_1->Executar();
    //entes[1]->Executar();
    //entes[2]->Executar();
    //fase1.Executar(); 
    //jogador_2.Executar();
    //fase1.Executar();
    Atualiza_Camera();
}
void Jogo::Atualiza_Camera() {	
    Ger_Graf->getJanela()->setView(*Ger_Graf->getCamera());
    sf::Vector2f v;
    v = jogador_1->get_Centro();
    v.y += 110.0f;
    Ger_Graf->getCamera()->setCenter(v);	
    //Ger_Graf->getJanela()->setView(m->getCamera());
     //setar o sf::View no modo default 	
}
void Jogo::incluirEntes(Ente *ente) {
	if(ente) {
		//ente->setpGG(Ger_Graf);
		entes.push_back(ente);
	}
}
Gerenciadores::Gerenciador_Grafico*  Jogo::getGerGraf() {
	return Ger_Graf;
}
void Jogo::percorreEntes() {	
	it = entes.begin();
	while(it != entes.end()) {
		(*it)->Executar();
 		it++;
	}
}
Entidades::Personagens::Jogador* Jogo::getJogador() {
	return jogador_1;
}
void Jogo::setJogador(Entidades::Personagens::Jogador* j) {
	if(j) { jogador_1 = j; }
}	
