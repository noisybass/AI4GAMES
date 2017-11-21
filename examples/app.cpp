#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML\Graphics.hpp"
#include <SFML\System\Clock.hpp>
#include <SFML\Window\Event.hpp>

#include "ai4games\Math\Vector2.h"
#include "ai4games\FSM\FSM.h"
#include "ai4games\SteeringBehaviours\SteeringAgent.h"

#include <iostream>

class SteeringBehavioursExample
{
public:
	SteeringBehavioursExample(sf::RenderWindow* renderWindow, Vector2 agentPos, Vector2 targetPos)
	{
		agent = new SteeringAgent(agentPos, 1.0f, 500000.0f);
		agent->Seek(targetPos);

		window = renderWindow;

		agentShape = sf::CircleShape(10, 4);
		agentShape.setOrigin(agentShape.getRadius(), agentShape.getRadius());
		agentShape.setRotation(45.0f);
		agentShape.setPosition(agentPos.x, agentPos.y);

		targetShape = sf::CircleShape(10, 4);
		targetShape.setOrigin(targetShape.getRadius(), targetShape.getRadius());
		targetShape.setRotation(45.0f);
		targetShape.setPosition(targetPos.x, targetPos.y);
	}

	void Update(float deltaTime)
	{
		agent->Update(deltaTime);
		std::cout << agent->Position().x << ", " << agent->Position().y << std::endl;
		agentShape.setPosition(agent->Position().x, agent->Position().y);

		window->draw(agentShape);
		window->draw(targetShape);
	}

private:
	sf::RenderWindow* window;
	SteeringAgent* agent;

	sf::CircleShape agentShape;
	sf::CircleShape targetShape;
};

int main(int argc, char **argv)
{
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(400, 300), "AI4GAMES");
	ImGui::SFML::Init(window);

	//sf::CircleShape square(100, 4);
	//square.setOrigin(square.getRadius(), square.getRadius());
	//square.setRotation(45.0f);
	//square.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	sf::Clock deltaClock;

	SteeringBehavioursExample* example = new SteeringBehavioursExample(&window, Vector2(100.0f, 100.0f), Vector2(200.0f, 200.0f));

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

		//window.draw(square);
		sf::Time elapsed = deltaClock.restart();
		example->Update(elapsed.asSeconds());

		ImGui::Render();

		window.display();

	}
}