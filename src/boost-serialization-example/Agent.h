#pragma once
#include "IAgent.h"
#include "common.h"

namespace jb2020 {

    class Agent :
        public IAgent
    {
    public:
        virtual int GetID() const noexcept override;

        virtual void Release() override;

        virtual ~Agent();
    public:
        Agent(){}
        Agent(int id);
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& m_id;
        }
    private:
        int m_id{};
    };

}

