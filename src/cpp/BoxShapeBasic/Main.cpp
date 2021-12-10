/*
 * This is a basic box shape collision test.
 * A floor is created using box shape with a very large size
 */

// Libraries
#include <reactphysics3d/reactphysics3d.h>
#include <iostream>

// ReactPhysics3D namespace
using namespace reactphysics3d;

// Main function
int main(int argc, char** argv) {

    // First you need to create the PhysicsCommon object. This is a factory module
    // that you can use to create physics world and other objects. It is also responsible
    // for logging and memory management
    PhysicsCommon physicsCommon;

    // Create a physics world
    PhysicsWorld* world = physicsCommon.createPhysicsWorld();

    // Create a rigid body in the world
    Vector3 position(0, 20, 0);
    Vector3 floorPosition(0, -1, 0);
    Quaternion orientation = Quaternion::identity();
    Transform transform(position, orientation);
    Transform floorTransform(floorPosition, orientation);
    RigidBody* body = world->createRigidBody(transform);
    RigidBody* floor = world->createRigidBody(floorTransform);
    floor->setType(BodyType::STATIC);
    
    // Half extents of the box in the x, y and z directions
    const Vector3 boxSize (2.0 , 3.0 , 5.0);
    const Vector3 floorSize (100000, 1, 100000);
    
    // Create the box shape
    BoxShape* boxShape = physicsCommon.createBoxShape(boxSize);
    BoxShape* floorShape = physicsCommon.createBoxShape(floorSize);
    Transform transform0 = Transform::identity();
    
    body->addCollider(boxShape, transform0);
    floor->addCollider(floorShape, transform0);
    
    // set damping, bounciness, friction
    body->setLinearDamping(0.01);
    Material& material = body->getCollider(0)->getMaterial();
    material.setBounciness(0.4);
    material.setFrictionCoefficient(0.2);

    // Set the initial speed
    Vector3 initVelocity(-1, 0, 0);
    body->setLinearVelocity(initVelocity);

    const decimal timeStep = 1.0f / 6.0f;

    // Step the simulation a few steps
    for (int i=0; i < 100; i++) {

        world->update(timeStep);

        // Get the updated position of the body
        const Transform& transform = body->getTransform();
        const Vector3& velocity = body->getLinearVelocity();
        const Vector3& position = transform.getPosition();
        const Vector3& orientation = transform.getOrientation().getVectorV();

        // Display the position of the body
        std::cout << "pos: (" << position.x << ", " << position.y << ", " << position.z << "); "
            << "v: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << ")" << std::endl;
    }

    return 0;
}
