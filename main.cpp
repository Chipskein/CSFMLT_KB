#include <SFML/Window.hpp>
#include <sfml/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	system("color 0e");
	// ocultar console
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	//ShowWindow(GetConsoleWindow(), SW_RESTORE);
// add songs
	int mus=0;
	string Music[3]={"track1.ogg","track2.ogg","track3.ogg"};
	sf::Music soundtrack;
	soundtrack.openFromFile(Music[mus]);
	soundtrack.play();	
	//sf::music .getStatus() 
	//0 stop
	//1 pause
	//2 play
//banco de palavras
	string palavras1[5] = { "teste","eaiman","judas","quale","debugger" };
	string palavras2[5] = { "deus","cavalo","joselito","function","macaco" };
	string palavras3[5] = { "cavalo","carro","cabelo","boca","maluco" };
	string palavras4[5] = { "tecnico","armario","top","bravo","doido" };
	string palavras5[5] = { "cacete","game","araujo","oracio","hermes" };
	string palavras6[5] = { "renato","canalha","cachorro","while","enquanto" };
	string palavras7[5] = { "jazz","desespero","medo","sorriso","aviso" };
	string palavras8[5] = { "calma","igreja","partida","goleiro","score" };
	string palavras9[5] = { "ofcina","escolas","hospitais","meninas","macete" };
	string palavras10[5] = { "vida","metodos","contra","nada","encontrar" };
// numeros random
	int random1 = rand() % 5;
	int random2 = rand() % 5;
	int random3 = rand() % 5;
	int random4 = rand() % 5;
	int random5 = rand() % 5;
	int random6 = rand() % 5;
	int random7 = rand() % 5;
	int random8 = rand() % 5;
	int random9 = rand() % 5;
	int random10 = rand() % 5;
//palavras selecionadas
	string palavra1 = palavras1[random1];
	string palavra2 = palavras2[random2];
	string palavra3 = palavras3[random3];
	string palavra4 = palavras4[random4];
	string palavra5 = palavras5[random5];
	string palavra6 = palavras6[random6];
	string palavra7 = palavras7[random7];
	string palavra8 = palavras8[random8];
	string palavra9 = palavras9[random9];
	string palavra10 = palavras10[random10];

//posiçoes
	int c1y = 1;
	int c2y = 1;
	int c3y = 1;
	int c4y = 1;
	int c5y = 1;
	int c6y = 1;
	int c7y = 1;
	int c8y = 1;
	int c9y = 1;
	int c10y = 1;
	float w=800.0;
	float h=400.0;
	int maxfall = 330;
	// limites da box do input
	size_t limitec = 20;
	// certos e errados
	int c = 0;
	int m = 0;
	
	
	//textos
	sf::Font font;
		font.loadFromFile("Broadway.ttf");
	//colunas
	sf::Text coluna1;
		coluna1.setFont(font);
		coluna1.setFillColor(sf::Color::Green);
		coluna1.setCharacterSize(20);
		coluna1.setString(palavra1);
		coluna1.setPosition(0,c1y);
	sf::Text coluna2;
		coluna2.setFont(font);
		coluna2.setFillColor(sf::Color::Green);
		coluna2.setCharacterSize(20);
		coluna2.setString(palavra2);
		coluna2.setPosition(80, c2y);
	sf::Text coluna3;
		coluna3.setFont(font);
		coluna3.setFillColor(sf::Color::Green);
		coluna3.setCharacterSize(20);
		coluna3.setString(palavra3);
		coluna3.setPosition(160, c3y);
	sf::Text coluna4;
		coluna4.setFont(font);
		coluna4.setFillColor(sf::Color::Green);
		coluna4.setCharacterSize(20);
		coluna4.setString(palavra4);
		coluna4.setPosition(240, c4y);
	sf::Text coluna5;
		coluna5.setFont(font);
		coluna5.setFillColor(sf::Color::Green);
		coluna5.setCharacterSize(20);
		coluna5.setString(palavra5);
		coluna5.setPosition(320, c5y);
	sf::Text coluna6;
		coluna6.setFont(font);
		coluna6.setFillColor(sf::Color::Green);
		coluna6.setCharacterSize(20);
		coluna6.setString(palavra6);
		coluna6.setPosition(400, c6y);
	sf::Text coluna7;
		coluna7.setFont(font);
		coluna7.setFillColor(sf::Color::Green);
		coluna7.setCharacterSize(20);
		coluna7.setString(palavra7);
		coluna7.setPosition(480, c7y);
	sf::Text coluna8;
		coluna8.setFont(font);
		coluna8.setFillColor(sf::Color::Green);
		coluna8.setCharacterSize(20);
		coluna8.setString(palavra8);
		coluna8.setPosition(560, c8y);
	sf::Text coluna9;
		coluna9.setFont(font);
		coluna9.setFillColor(sf::Color::Green);
		coluna9.setCharacterSize(20);
		coluna9.setString(palavra9);
		coluna9.setPosition(640, c9y);
	sf::Text coluna10;
		coluna10.setFont(font);
		coluna10.setFillColor(sf::Color::Green);
		coluna10.setCharacterSize(20);
		coluna10.setString(palavra10);
		coluna10.setPosition(720, c10y);
		
	//layout
	sf::Text certos;
		certos.setFont(font);
		certos.setPosition(300, h - 40);
		certos.setString("Certos:"+to_string(c));
		certos.setFillColor(sf::Color::Green);
	sf::Text errados;
		errados.setFont(font);
		errados.setPosition(650, h - 40);
		errados.setString("Errados:" + to_string(m));
		errados.setFillColor(sf::Color::Red);
	sf::Text clocks;
		string clocktime = "0:0:0";
		clocks.setFont(font);
		clocks.setPosition(525, h - 40);
		clocks.setCharacterSize(22);
		clocks.setFillColor(sf::Color::Black);
	sf::Text input;
		string pal="";
		input.setFont(font);
		input.setPosition(5, h - 40);
		input.setCharacterSize(22);
		input.setFillColor(sf::Color::Black);
	//window e formas
	sf::RenderWindow window(sf::VideoMode(800,400), "KeyBoardGame");
	sf::RectangleShape field(sf::Vector2f(w, h - 50));
	sf::Texture bg;
		bg.loadFromFile("space.png");
		field.setTexture(&bg);
	sf::Image icon;
		icon.loadFromFile("icon.png");
		window.setIcon(200,200,icon.getPixelsPtr());
	sf::RectangleShape boxclock(sf::Vector2f(w / 8, h / 10));
		boxclock.setFillColor(sf::Color::White);
		boxclock.setPosition(500, h - 45);
	sf::RectangleShape botom(sf::Vector2f(w,h/4));
		botom.setPosition(0, h - 50);
		botom.setFillColor(sf::Color::Color(36, 51, 85,255));
	sf::RectangleShape boxinput(sf::Vector2f(w/4,h/10));
		boxinput.setFillColor(sf::Color::White);
		boxinput.setPosition(5, h - 45);
	//game loop
		window.setKeyRepeatEnabled(0);
	// mudar cronometro
		int min = 0;
		int seg = 0;
		int minseg = 0;
	while (window.isOpen()) {
		sf::Event e;
		printf("%d", soundtrack.getStatus());
		if (soundtrack.getStatus()==0)
		{
			mus++;
			if (mus>2)
			{
				mus = 0;
			}
			soundtrack.openFromFile(Music[mus]);
			soundtrack.play();
		}
		//colunas
		Sleep(30);
		if (c1y<=330)
		{
			if (c1y==330)
			{
				c1y = 1;
				coluna1.setPosition(0, c1y);

				random1 = rand() % 5;
				palavra1 = palavras1[random1];
				coluna1.setString(palavra1);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c1y <= 110)
			{
				coluna1.setFillColor(sf::Color::Green);
			}
			if (c1y > 110&& c1y <= 210)
			{
				coluna1.setFillColor(sf::Color::Yellow);
			}
			if (c1y > 210)
			{
				coluna1.setFillColor(sf::Color::Red);
			}
			coluna1.setPosition(0, c1y);
			
			c1y++;//max =330
		}
		
		if (c2y <= 330)
		{
			if (c2y == 330)
			{
				c2y = 1;
				coluna2.setPosition(80, c2y);

				random2 = rand() % 5;
				palavra2 = palavras2[random2];
				coluna2.setString(palavra2);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c2y <= 110)
			{
				coluna2.setFillColor(sf::Color::Green);
			}
			if (c2y > 110 && c2y <= 210)
			{
				coluna2.setFillColor(sf::Color::Yellow);
			}
			if (c2y > 210)
			{
				coluna2.setFillColor(sf::Color::Red);
			}
			coluna2.setPosition(80, c2y);
			
			c2y++;//max =330
		}
		
		if (c3y <= 330)
		{
			if (c3y == 330)
			{
				c3y = 1;
				coluna3.setPosition(160, c3y);

				random3 = rand() % 5;
				palavra3 = palavras3[random3];
				coluna3.setString(palavra3);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c3y <= 110)
			{
				coluna3.setFillColor(sf::Color::Green);
			}
			if (c3y > 110 && c3y <= 210)
			{
				coluna3.setFillColor(sf::Color::Yellow);
			}
			if (c3y > 210)
			{
				coluna3.setFillColor(sf::Color::Red);
			}
			coluna3.setPosition(160, c3y);
			c3y++;//max =330
		}

		if (c4y <= 330)
		{
			if (c4y == 330)
			{
				c4y = 1;
				coluna4.setPosition(240, c4y);

				random4 = rand() % 5;
				palavra4 = palavras4[random4];
				coluna4.setString(palavra4);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c4y <= 110)
			{
				coluna4.setFillColor(sf::Color::Green);
			}
			if (c4y > 110 && c4y <= 210)
			{
				coluna4.setFillColor(sf::Color::Yellow);
			}
			if (c4y > 210)
			{
				coluna4.setFillColor(sf::Color::Red);
			}
			coluna4.setPosition(240, c4y);
			c4y++;//max =330
		}
		
		if (c5y <= 330)
		{
			if (c5y == 330)
			{
				c5y = 1;
				coluna5.setPosition(320, c5y);

				random5 = rand() % 5;
				palavra5 = palavras5[random5];
				coluna5.setString(palavra5);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c5y <= 110)
			{
				coluna5.setFillColor(sf::Color::Green);
			}
			if (c5y > 110 && c5y <= 210)
			{
				coluna5.setFillColor(sf::Color::Yellow);
			}
			if (c5y > 210)
			{
				coluna5.setFillColor(sf::Color::Red);
			}
			coluna5.setPosition(320, c5y);
			c5y++;//max =330
		}
		
		if (c6y <= 330)
		{
			if (c6y == 330)
			{
				c6y = 1;
				coluna6.setPosition(400, c6y);

				random6 = rand() % 5;
				palavra6 = palavras6[random6];
				coluna6.setString(palavra6);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c6y <= 110)
			{
				coluna6.setFillColor(sf::Color::Green);
			}
			if (c6y > 110 && c6y <= 210)
			{
				coluna6.setFillColor(sf::Color::Yellow);
			}
			if (c6y > 210)
			{
				coluna6.setFillColor(sf::Color::Red);
			}
			coluna6.setPosition(400, c6y);
			c6y++;//max =330
		}
		
		if (c7y <= 330)
		{
			if (c7y == 330)
			{
				c7y = 1;
				coluna7.setPosition(480, c7y);

				random7 = rand() % 5;
				palavra7 = palavras2[random7];
				coluna7.setString(palavra7);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c7y <= 110)
			{
				coluna7.setFillColor(sf::Color::Green);
			}
			if (c7y > 110 && c7y <= 210)
			{
				coluna7.setFillColor(sf::Color::Yellow);
			}
			if (c7y > 210)
			{
				coluna7.setFillColor(sf::Color::Red);
			}
			coluna7.setPosition(480, c7y);
			c7y++;//max =330
		}
		
		if (c8y <= 330)
		{
			if (c8y == 330)
			{
				c8y = 1;
				coluna8.setPosition(560, c3y);

				random8 = rand() % 5;
				palavra8 = palavras8[random8];
				coluna8.setString(palavra8);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c8y <= 110)
			{
				coluna8.setFillColor(sf::Color::Green);
			}
			if (c8y > 110 && c8y <= 210)
			{
				coluna8.setFillColor(sf::Color::Yellow);
			}
			if (c8y > 210)
			{
				coluna8.setFillColor(sf::Color::Red);
			}
			coluna8.setPosition(560, c8y);
			c8y++;//max =330
		}
		
		if (c9y <= 330)
		{
			if (c9y == 330)
			{
				c9y = 1;
				coluna9.setPosition(640, c3y);

				random9 = rand() % 5;
				palavra9 = palavras9[random9];
				coluna9.setString(palavra9);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c9y <= 110)
			{
				coluna9.setFillColor(sf::Color::Green);
			}
			if (c9y > 110 && c9y <= 210)
			{
				coluna9.setFillColor(sf::Color::Yellow);
			}
			if (c9y > 210)
			{
				coluna9.setFillColor(sf::Color::Red);
			}
			coluna9.setPosition(640, c9y);
			c9y++;//max =330
		}
		
		if (c10y <= 330)
		{
			if (c10y == 330)
			{
				c10y = 1;
				coluna10.setPosition(720, c3y);

				random10 = rand() % 5;
				palavra10 = palavras10[random10];
				coluna10.setString(palavra10);
				m++;
				errados.setString("Errados:" + to_string(m));
			}
			if (c10y <= 110)
			{
				coluna10.setFillColor(sf::Color::Green);
			}
			if (c10y > 110 && c10y <= 210)
			{
				coluna10.setFillColor(sf::Color::Yellow);
			}
			if (c10y > 210)
			{
				coluna10.setFillColor(sf::Color::Red);
			}
			coluna10.setPosition(720, c10y);
			c10y++;//max =330
		}
		input.setString(pal);
		clocks.setString(clocktime);
		clocktime = (to_string(min)) + ":" + (to_string(seg)) + ":" + (to_string(minseg));
		
			if (minseg == 1000)
			{
				minseg = 0;
				seg++;				
			}
			if (seg == 60)
			{
				min++;
				seg = 0;
			}
			Sleep(1);
			minseg++;
			
		
		while (window.pollEvent(e))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{	
				//verificar
				if (pal==palavra1)
				{
					c1y = 1;
					coluna1.setPosition(0, c1y);
					
					random1 = rand() % 5;
					palavra1 = palavras1[random1];
					coluna1.setString(palavra1);
					
					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";
					
				}
				
				if (pal == palavra2)
				{
					c2y = 1;
					coluna2.setPosition(80, c2y);

					random2 = rand() % 5;
					palavra2 = palavras2[random2];
					coluna2.setString(palavra2);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra3)
				{
					c3y = 1;
					coluna3.setPosition(160, c3y);

					random3 = rand() % 5;
					palavra3 = palavras3[random3];
					coluna3.setString(palavra3);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra4)
				{
					c4y = 1;
					coluna4.setPosition(240, c4y);

					random4 = rand() % 5;
					palavra4 = palavras4[random4];
					coluna4.setString(palavra4);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra5)
				{
					c5y = 1;
					coluna5.setPosition(320, c5y);

					random5 = rand() % 5;
					palavra5 = palavras5[random5];
					coluna5.setString(palavra5);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra6)
				{
					c6y = 1;
					coluna6.setPosition(400, c6y);

					random6 = rand() % 5;
					palavra6 = palavras6[random6];
					coluna6.setString(palavra6);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				
				if (pal == palavra7)
				{
					c7y = 1;
					coluna7.setPosition(480, c7y);

					random7 = rand() % 5;
					palavra7 = palavras7[random7];
					coluna7.setString(palavra7);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra8)
				{
					c8y = 1;
					coluna8.setPosition(560, c8y);

					random8 = rand() % 5;
					palavra8 = palavras8[random8];
					coluna8.setString(palavra8);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra9)
				{
					c9y = 1;
					coluna9.setPosition(640, c9y);

					random9 = rand() % 5;
					palavra9 = palavras9[random9];
					coluna9.setString(palavra9);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
				
				if (pal == palavra10)
				{
					c10y = 1;
					coluna10.setPosition(720, c10y);

					random10 = rand() % 5;
					palavra10 = palavras10[random10];
					coluna10.setString(palavra10);

					c++;
					certos.setString("Certos:" + to_string(c));
					pal = "";

				}
			}
			if (e.type==sf::Event::TextEntered){
				if (e.text.unicode<128)
				{
					char letra;
					letra = (char)e.text.unicode;
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)&&pal.size()<=limitec&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						
						pal += letra;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						m++;
						errados.setString("Errados:" + to_string(m));
						pal = "";
					}
				}
			}
			if (e.type==sf::Event::Closed){
				window.close();
			}
			
		}
		
		window.draw(field);
		window.draw(botom);
		window.draw(boxinput);
		window.draw(boxclock);
		window.draw(input);
		window.draw(clocks);
		window.draw(coluna1);
		window.draw(coluna2);
		window.draw(coluna3);
		window.draw(coluna4);
		window.draw(coluna5);
		window.draw(coluna6);
		window.draw(coluna7);
		window.draw(coluna8);
		window.draw(coluna9);
		window.draw(coluna10);
		window.draw(certos);
		window.draw(errados);
		
		window.display();
		}
	
	return 0;
}