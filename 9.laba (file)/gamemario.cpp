#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	
	RenderWindow window( VideoMode(200, 200), "Test!");
	
	CircleShape MyCircle(100.f);
	MyCircle.setFillColor(Color::Green);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
	return 0;
}
