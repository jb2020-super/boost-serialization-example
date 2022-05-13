#include "Vehical.h"

namespace jb2020 {
	double Vehical::GetSpeed() const noexcept
	{
		return m_speed;
	}

	void Vehical::Release()
	{
		delete this;
	}

	Vehical::~Vehical()
	{
	}

	Vehical::Vehical(double speed):
		m_speed{ speed }
	{
	}
}