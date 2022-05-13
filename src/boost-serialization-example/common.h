#pragma once


#include <list>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#define BOOST_ALL_DYN_LINK
#include "boost/serialization/serialization.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/unique_ptr.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/export.hpp"

struct PtrDeleter {
	template<class T>
	void operator()(T* obj) {
		if (obj) {
			obj->Release();
		}
	}
};
template<class T>
using UniquePtr = std::unique_ptr<T, PtrDeleter>;