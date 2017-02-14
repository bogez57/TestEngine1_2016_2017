#include "Precompiled.h"
#include "Universal/Globals.h"
#include "Components/Velocity.h"
#include "GameWorld/SceneManager.h"
#include "Components/Position.h"
#include "MovementSystem.h"

MovementSystem::MovementSystem()
{
}

MovementSystem::~MovementSystem()
{
}

bool MovementSystem::Initialize()
{
	return false;
}

bool MovementSystem::Shutdown()
{
	return false;
}

void MovementSystem::Update(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//render bit mask (which entity 'keys' fit into the render 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & MOVEMENT_MASK) == MOVEMENT_MASK)
		{
			PositionComponent* entityPosition = &scene.positionComponents.at(entity);
			VelocityComponent* entityVelocity = &scene.velocityComponents.at(entity);
			
			entityPosition->position += (entityVelocity->velocity * engineClock.TimeSinceLastFrame());

			entityVelocity->velocity.x = 0;
			entityVelocity->velocity.y = 0;
		}
	}
}
