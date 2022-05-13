#include "Scene.h"
#include "Agent.h"
#include "Vehical.h"

#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"
//#include "boost/archive/binary_woarchive.hpp"
//#include "boost/archive/binary_wiarchive.hpp"

#include "official_example.h"

using namespace jb2020;



//BOOST_SERIALIZATION_ASSUME_ABSTRACT(::jb2020::IAgent)
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(::jb2020::IVehical)
BOOST_CLASS_EXPORT_GUID(::jb2020::Agent, "0979F7E1-2932-4D10-8F62-412F3CC492DD")
BOOST_CLASS_EXPORT_GUID(::jb2020::Vehical, "DF65DC5D-95E2-4157-ACB3-206280758890")


void test_scene()
{
    Scene scene;
    IAgent* agent = new Agent(10);
    IVehical* veh = new Vehical(5.0);
    scene.PushBack(agent);
    scene.PushBack(veh);
    std::cout << "Game object count in scene: " << scene.GetGOCount() << std::endl;

    std::ofstream ofs("scene.jb2020");
    if (ofs.is_open()) {
        boost::archive::binary_oarchive bo(ofs);
        bo << scene;
    }
    else
    {
        std::cout << "Open file failed\n";
        return ;
    }

    std::ifstream ifs("scene.jb2020");
    if (ifs.is_open()) {
        boost::archive::binary_iarchive bi(ifs);
        Scene scene0;
        bi >> scene0;
        std::cout << "New Scene game object count: " << scene0.GetGOCount() << std::endl;
    }
}

//void test_scene_wstream()
//{
//    Scene scene;
//    IAgent* agent = new Agent(10);
//    IVehical* veh = new Vehical(5.0);
//    scene.PushBack(agent);
//    scene.PushBack(veh);
//    std::cout << "Game object count in scene: " << scene.GetGOCount() << std::endl;
//
//    std::wofstream ofs(L"scene_wstream.jb2020");
//    if (ofs.is_open()) {
//        boost::archive::binary_woarchive bo(ofs);
//        bo << scene;
//    }
//    else
//    {
//        std::cout << "Open file failed\n";
//        return;
//    }
//
//    std::wifstream ifs(L"scene_wstream.jb2020");
//    if (ifs.is_open()) {
//        boost::archive::binary_wiarchive bi(ifs);
//        Scene scene0;
//        bi >> scene0;
//        std::cout << "New Scene game object count: " << scene0.GetGOCount() << std::endl;
//    }
//}

void test_scene(const wchar_t* url)
{
    Scene scene;
    IAgent* agent = new Agent(10);
    IVehical* veh = new Vehical(5.0);
    scene.PushBack(agent);
    scene.PushBack(veh);
    std::cout << "Game object count in scene: " << scene.GetGOCount() << std::endl;
    ;
    std::ofstream ofs;
    ofs.open(url);
    if (ofs.is_open()) {
        boost::archive::binary_oarchive bo(ofs);
        bo << scene;
    }
    else
    {
        std::cout << "Open file failed\n";
        return;
    }

    std::ifstream ifs;
    ifs.open(url);
    if (ifs.is_open()) {
        boost::archive::binary_iarchive bi(ifs);
        Scene scene0;
        bi >> scene0;
        std::cout << "New Scene game object count: " << scene0.GetGOCount() << std::endl;
    }
}

int main()
{
    //official_example();
    //test_scene();
    test_scene(L"你好.bin");
    return 0;
}
