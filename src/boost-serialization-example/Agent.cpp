#include "Agent.h"

namespace jb2020 {

	int Agent::GetID() const noexcept
	{
		return m_id;
	}

	void Agent::Release()
	{
		delete this;
	}

	Agent::~Agent()
	{
	}

	Agent::Agent(int id):
		m_id{ id }
	{
	}

}