// Converted by Dice Simulation 0.0.4 at 2021-12-15 13:57:06 UTC.

#include "ds_global.ds-h"
#include "ds_core.ds-h"

const char* ds_version = "0.0.4";
double gravity = 9.81;

int main(int argc, char* argv[]) {
    PhysicsCommon physicsCommon;
    PhysicsWorld* world = physicsCommon.createPhysicsWorld();
    BoxShape* floorShape = physicsCommon.createBoxShape(Vector3(1000000, 1, 1000000));
    RigidBody* floor = world->createRigidBody(Vector3(0, -1, 0), Quaternion::identity());
    floor->setType(BodyType::STATIC);
    floor>addCollider(floorShape, Transform::identity());
    for (int i = 0; i != 100; i++) {
    }
    return 0;
}

