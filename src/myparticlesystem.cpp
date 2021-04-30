// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) {
    mTexture = theRenderer.loadTexture("../textures/ParticleSquare.png");

    Particle p = {
            vec3(0),
            vec3(0.5, 0, 0),
            vec4(1, 0.4, 0, 1),
            0.1,
            1
    };
    mParticles.push_back(p);
}

void MyParticleSystem::update(float dt) {
    Particle& head = mParticles[0];

    // trail
    Particle trail = {
            head.pos,
            vec3(0),
            head.color,
            head.size,
            head.mass
    };
    mParticles.push_back(trail);

    // head
    if (head.vel.x != 0) {
        if (lastPressedKey == GLFW_KEY_UP) {
            head.vel.x = 0;
            head.vel.y = 0.5;
        } else if (lastPressedKey == GLFW_KEY_DOWN) {
            head.vel.x = 0;
            head.vel.y = -0.5;
        }
    } else {
        if (lastPressedKey == GLFW_KEY_LEFT) {
            head.vel.y = 0;
            head.vel.x = -0.5;
        } else if (lastPressedKey == GLFW_KEY_RIGHT) {
            head.vel.y = 0;
            head.vel.x = 0.5;
        }
    }

    head.pos = head.pos + dt * head.vel;
    head.vel = head.vel + dt * 0 / head.mass;

    if (head.pos.x >= 1) {
        head.pos.x -= 2;
    }
    if (head.pos.y >= 1) {
        head.pos.y -= 2;
    }
    if (head.pos.x <= -1) {
        head.pos.x += 2;
    }
    if (head.pos.y <= -1) {
        head.pos.y += 2;
    }

    for (int i = 1; i < mParticles.size(); ++i) {
        mParticles[i].color.w -= 0.01;
    }

    mParticles.erase(std::remove_if(mParticles.begin(), mParticles.end(),
                                    [](const Particle& p) {
        return p.color.w <= 0;
    }), mParticles.end());
}

void MyParticleSystem::setKeyPressed(int key) {
    lastPressedKey = key;
}
