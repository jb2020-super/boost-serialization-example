#pragma once
#include "IGameObject.h"

namespace jb2020
{
	class IScene
	{
	public:
		virtual size_t GetGOCount() const noexcept = 0;

		virtual IGameObject* GetGO(int idx) = 0;

		virtual void PushBack(IGameObject* go) = 0;

		virtual void Release() = 0;
	protected:
		virtual ~IScene(){}
	};
}