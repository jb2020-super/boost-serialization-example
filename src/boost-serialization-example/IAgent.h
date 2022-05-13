#pragma once
#include "IGameObject.h"

namespace jb2020 {
	class IAgent :
		public IGameObject
	{
	public:
		virtual int GetID() const noexcept = 0;
	protected:
		virtual ~IAgent(){}
	};
}