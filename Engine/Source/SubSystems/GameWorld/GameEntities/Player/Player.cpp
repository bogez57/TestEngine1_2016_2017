#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "Input/Input.h"
#include "Input/PlayerController.h"
#include "Physics/Physics.h"
#include "Universal/Globals.h"
#include "Player.h"

namespace BlazeGameWorld
{
	Player::Player() :
		Pawn(new BlazeInput::PlayerController)
	{
	}

	Player::~Player()
	{
	}

	bool Player::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Pawn::Initialize(startPosition, geometry);

		return true;
	}

	bool Player::Shutdown()
	{
		Entity::Shutdown();
		controller->Shutdown();

		return true;
	}

	void Player::Update()
	{
		controller->Update(*this);
		physics->Update(*this);
		renderer->Update(*this);

		//Have to zero out velocity after updating every frame so that key input doesn't compound and 
		//cause the object to move in a direction its not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}
}