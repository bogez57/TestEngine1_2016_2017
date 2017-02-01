#pragma once
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput { class Controller; }

namespace BlazeGameWorld
{
	class Pawn : public Entity
	{
	public:

	protected:
		std::unique_ptr<BlazeInput::Controller> controller;

	private:

		///////////////////////////////////////////////////////////////////////

	public:
		Pawn();
		~Pawn();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry) override;

		virtual void Update() override;

	protected:
		Pawn(BlazeInput::Controller* controller);

	private:
	};
}