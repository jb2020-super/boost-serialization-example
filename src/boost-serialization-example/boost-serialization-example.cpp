#include "Scene.h"
#include "Agent.h"
#include "Vehical.h"
//#define BOOST_ALL_DYN_LINK
#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
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



double num = 3.1415926;

void test_text_archive_save(const wchar_t* url)
{
    std::ofstream ofs;
    ofs.open(url);
    if (ofs.is_open()) {
        boost::archive::text_oarchive to(ofs);        
        to << num;
    }
    else
    {
        std::cout << "Open file failed\n";
        return;
    }
    
}

void test_text_archive_load(const wchar_t* url)
{
    std::ifstream ifs;
    ifs.open(url);
    if (ifs.is_open()) {
        boost::archive::text_iarchive to(ifs);
        double num0{};
        to >> num0;
        std::cout << num0 << std::endl;
    }
    else
    {
        std::cout << "Open file failed\n";
        return;
    }

}

int main()
{
    //official_example();
    //test_scene();
    //test_scene(L"你好.bin");
    const wchar_t* url = L"text_arch.txt";
#if defined _WIN64
    test_text_archive_save(url);
#else
    test_text_archive_load(url);
#endif
    return 0;
}
