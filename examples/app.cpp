#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML\Graphics.hpp"
#include <SFML\System\Clock.hpp>
#include <SFML\Window\Event.hpp>

#include "ai4games\Math\Vector2.h"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "AI4GAMES");
	ImGui::SFML::Init(window);

	sf::CircleShape square(100, 4);
	square.setOrigin(square.getRadius(), square.getRadius());
	square.setRotation(45.0f);
	square.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

		}

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Example", NULL, ImGuiWindowFlags_AlwaysAutoResize); // begin window

		ImGui::End(); // end window

		window.clear();

		window.draw(square);

		ImGui::Render();

		window.display();

	}
}