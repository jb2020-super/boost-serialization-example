#pragma once
#include "IGameObject.h"

namespace jb2020 {
	class IVehical :
		public IGameObject
	{
	public:
		virtual double GetSpeed() const noexcept = 0;
	protected:
		virtual ~IVehical(){}
	};
}