#ifndef MyParticleSystem_H_
#define MyParticleSystem_H_

#include "particlesystem.h"

namespace agl {

    class MyParticleSystem : public ParticleSystem {
    public:
        virtual void createParticles(int size) override;
        virtual void update(float dt) override;
        void setKeyPressed(int key);

    private:
        int lastPressedKey = -1;
    };
}
#endif