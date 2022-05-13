#pragma once
#include "IScene.h"
#include "common.h"
#include "Agent.h"
#include "Vehical.h"



namespace jb2020 {
    BOOST_SERIALIZATION_ASSUME_ABSTRACT(::jb2020::IGameObject)



    class Scene :
        public IScene
    {
    public:
        virtual size_t GetGOCount() const noexcept override;

        virtual IGameObject* GetGO(int idx) override;

        virtual void Release();

        virtual void PushBack(IGameObject* go) override;

        virtual ~Scene();

    public:
        Scene();
    private:
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            boost::serialization::void_cast_register<Agent, IGameObject>();
            boost::serialization::void_cast_register<Vehical, IGameObject>();
            ar& m_gos;
        }       
    private:
        std::vector<std::unique_ptr<IGameObject>> m_gos;
    };

}

