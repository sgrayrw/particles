// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"
#include <cstdlib>

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) {
    mTexture = theRenderer.loadTexture("../textures/particle.png");

    // Create particles
    for (int i = 0; i < size; ++i) {
        mParticles.push_back({
             vec3(random_float(-1, 1), random_float(-1, 1), random_float(-1, 1)),
             vec3(random_float(-1, 1), random_float(-1, 1), random_float(-1, 1)),
             vec4(random_float(0, 0.5), random_float(0, 0.5), random_float(0, 0.5), 1),
             0.25f,
             1.0f
        });
    }
}

void Confetti::update(float dt) {
    for (auto& particle : mParticles) {
        particle.pos = particle.pos + dt * particle.vel;
        particle.vel = particle.vel + dt * 0 / particle.mass;

        if (abs(particle.pos.x) >= 1) {
            particle.vel.x *= -1;
        }
        if (abs(particle.pos.y) >= 1) {
            particle.vel.y *= -1;
        }
        if (abs(particle.pos.z) >= 1) {
            particle.vel.z *= -1;
        }

        // sort
        vec3 cameraPos = theRenderer.cameraPosition();
        //for (int i = 1; i < mParticles.size(); ++i) {
        //    float d1 = distance(mParticles[i].pos, cameraPos);
        //    float d2 = distance(mParticles[i - 1].pos, cameraPos);
        //    if (d2 < d1) {
        //        swap(mParticles[i], mParticles[i - 1]);
        //    }
        //}
        sort(mParticles.begin(), mParticles.end(),
             [&](const Particle& p1, const Particle& p2) -> bool {
            return distance(p1.pos, cameraPos) > distance(p2.pos, cameraPos);
        });
    }
}
