#pragma once

#include "common.h"

namespace jb2020 
{
	class IGameObject
	{
	public:
		virtual void Release() = 0;
	//protected:
		virtual ~IGameObject(){}
	//private:
	//	friend class boost::serialization::access;
	//	template<class Archive> void serialize(Archive&, unsigned) { }
	};

}

