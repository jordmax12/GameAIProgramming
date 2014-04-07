#include "Referee.h"
#include "misc/Cgdi.h"
#include "SteeringBehaviors.h"
#include "SoccerTeam.h"
#include "SoccerPitch.h"
#include "2D/transformations.h"
#include "GoalKeeperStates.h"
#include "Goal.h"
#include "game/EntityFunctionTemplates.h"
#include "ParamLoader.h"

using std::vector;
//----------------------------- dtor ------------------------------------
//-----------------------------------------------------------------------
Referee::~Referee()
{
	delete m_pStateMachine;
}
//----------------------------- ctor ------------------------------------
//-----------------------------------------------------------------------
Referee::Referee(SoccerTeam*        home_team,
	int                home_region,
	State<Referee>* start_state,
	Vector2D           heading,
	Vector2D           velocity,
	double              mass,
	double              max_force,
	double              max_speed,
	double              max_turn_rate,
	double              scale,
	player_role role) : PlayerBase(home_team,
	home_region,
	heading,
	velocity,
	mass,
	max_force,
	max_speed,
	max_turn_rate,
	scale,
	PlayerBase::referee)


{
	//set up the state machine
	m_pStateMachine = new StateMachine<Referee>(this); //

	m_pStateMachine->SetCurrentState(start_state); //
	m_pStateMachine->SetPreviousState(start_state); //
	m_pStateMachine->SetGlobalState(GlobalRefereeState::Instance()); //

	m_pStateMachine->CurrentState()->Enter(this); //
}



//-------------------------- Update --------------------------------------

void Referee::Update() //
{
	//run the logic for the current state
	m_pStateMachine->Update(); //

	//calculate the combined force from each steering behavior 
	Vector2D SteeringForce = m_pSteering->Calculate(); //



	//Acceleration = Force/Mass
	Vector2D Acceleration = SteeringForce / m_dMass; //

	//update velocity
	m_vVelocity += Acceleration; //

	//make sure player does not exceed maximum velocity
	m_vVelocity.Truncate(m_dMaxSpeed); //

	//update the position
	m_vPosition += m_vVelocity; //


	//enforce a non-penetration constraint if desired
	if (Prm.bNonPenetrationConstraint) //
	{
		EnforceNonPenetrationContraint(this, AutoList<PlayerBase>::GetAllMembers());
	}

	//update the heading if the player has a non zero velocity //
	if (!m_vVelocity.isZero())
	{
		m_vHeading = Vec2DNormalize(m_vVelocity);

		m_vSide = m_vHeading.Perp();
	}

	//look-at vector always points toward the ball //
	if (!Pitch()->GoalKeeperHasBall())
	{
		m_vLookAt = Vec2DNormalize(Ball()->Pos() - Pos());
	}
}

//--------------------------- Render -------------------------------------
//
//------------------------------------------------------------------------
void Referee::Render()
{
	if (Team()->Color() == SoccerTeam::green)
		gdi->GreenPen();
	else
		gdi->PurplePen();

	m_vecPlayerVBTrans = WorldTransform(m_vecPlayerVB,
		Pos(),
		m_vLookAt,
		m_vLookAt.Perp(),
		Scale());

	gdi->ClosedShape(m_vecPlayerVBTrans);

	//draw the head
	gdi->BrownBrush();
	gdi->Circle(Pos(), 6);

	//draw the ID
	if (Prm.bIDs)
	{
		gdi->TextColor(0, 170, 0);;
		gdi->TextAtPos(Pos().x - 20, Pos().y - 20, ttos(ID()));
	}
}