#pragma once
#include "IVehical.h"
#include "common.h"

namespace jb2020 {

    class Vehical :
        public IVehical
    {
    public:
        virtual double GetSpeed() const noexcept override;

        virtual void Release() override;

        virtual ~Vehical();

    public:
        Vehical(){}
        Vehical(double speed);
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& m_speed;
        }
    private:
        double m_speed{};
    };

}
