/*
 * This is a basic cylinder shape collision test.
 * A floor is created using box shape with a very large size.
 * The cylinder shape is approximated using ConvexMeshShape.
 */

// Libraries
#include <reactphysics3d/reactphysics3d.h>
#include <iostream>
#include <cmath>

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
    Vector3 floorPosition(0, -100, 0);
    Quaternion orientation = Quaternion::identity();
    Transform transform(position, orientation);
    Transform floorTransform(floorPosition, orientation);
    RigidBody* floor = world->createRigidBody(floorTransform);
    floor->setType(BodyType::STATIC);
    
    // Half extents of the box in the x, y and z directions
    const Vector3 floorSize (100000, 100, 100000);
    
    
    // ====== Create a Cylinder ======
    // Be cafeful to set vertices of a face as counter clockwise
    // order as seen from the outside of your convex mesh.
    
    RigidBody* body = world->createRigidBody(transform);
    
    const int   cylinderSides = 4;
    const float cylinderR     = 5;
    const float cylinderH     = 4;
    // Array with the vertices coordinates of the convex mesh
    float vertices[6 * cylinderSides]; // 2 * cylinderSides * 3
    for (int i = 0; i != cylinderSides; i++) {
        vertices[3 * i] = cylinderR * std::cos(2 * 3.14159265358979 * i / cylinderSides);
        vertices[3 * i + 1] = -cylinderH / 2;
        vertices[3 * i + 2] = cylinderR * std::sin(2 * 3.14159265358979 * i / cylinderSides);
        vertices[3 * (cylinderSides + i)] = vertices[3 * i];
        vertices[3 * (cylinderSides + i) + 1] = cylinderH / 2;
        vertices[3 * (cylinderSides + i) + 2] = vertices[3 * i + 2];
    }
    // Array with the vertices indices for each face of the mesh
    int indices[6 * cylinderSides]; // 4 * cylinderSides + cylinderSides * 2
    for (int i = 0; i != cylinderSides - 1; i++) {
        // side face
        indices[4 * i    ] = i;
        indices[4 * i + 1] = i + 1;
        indices[4 * i + 2] = cylinderSides + i + 1;
        indices[4 * i + 3] = cylinderSides + i;
        // top and bottom face
        indices[4 * cylinderSides + i] = cylinderSides - i - 1;
        indices[5 * cylinderSides + i] = cylinderSides + i;
    }
    indices[4 * cylinderSides - 4] = cylinderSides - 1;
    indices[4 * cylinderSides - 3] = 0;
    indices[4 * cylinderSides - 2] = cylinderSides;
    indices[4 * cylinderSides - 1] = 2 * cylinderSides - 1;
    indices[5 * cylinderSides - 1] = 0;
    indices[6 * cylinderSides - 1] = 2 * cylinderSides - 1;
    // Description of the (cylinderSides + 2) faces of the convex mesh
    PolygonVertexArray::PolygonFace polygonFaces[cylinderSides + 2];
    // PolygonVertexArray::PolygonFace* face = polygonFaces;
    for (int f = 0; f != cylinderSides; f++) { // first for side faces
        // First vertex of the face in the indices array
        polygonFaces[f].indexBase = f * 4;
        // Number of vertices in the face
        polygonFaces[f].nbVertices = 4;
    }
    polygonFaces[cylinderSides].indexBase = cylinderSides * 4;
    polygonFaces[cylinderSides].nbVertices = cylinderSides;
    polygonFaces[cylinderSides + 1].indexBase = cylinderSides * 5;
    polygonFaces[cylinderSides + 1].nbVertices = cylinderSides;
    
    // Create the polygon vertex array
    PolygonVertexArray * polygonVertexArray = new PolygonVertexArray(
        2 * cylinderSides, vertices, 3 * sizeof(float), indices,
        sizeof(int), cylinderSides + 2 , polygonFaces,
        PolygonVertexArray::VertexDataType::VERTEX_FLOAT_TYPE,
        PolygonVertexArray::IndexDataType::INDEX_INTEGER_TYPE);
    
    // Create the polyhedron mesh
    PolyhedronMesh* polyhedronMesh = physicsCommon.createPolyhedronMesh(polygonVertexArray);
    // Create the convex mesh collision shape
    ConvexMeshShape* cylinderShape = physicsCommon.createConvexMeshShape(polyhedronMesh);
    body->addCollider(cylinderShape, Transform::identity());
    
    // Create the box shape
    // BoxShape* boxShape = physicsCommon.createBoxShape(boxSize);
    BoxShape* floorShape = physicsCommon.createBoxShape(floorSize);
    Transform transform0 = Transform::identity();
    
    floor->addCollider(floorShape, transform0);
    
    // set damping, bounciness, friction
    body->setLinearDamping(0.01);
    Material& material = body->getCollider(0)->getMaterial();
    material.setBounciness(0.4);
    material.setFrictionCoefficient(0.2);

    // Set the initial speed
    Vector3 initVelocity(-1, 0, 0);
    body->setLinearVelocity(initVelocity);

    const decimal timeStep = 1.0f / 60.0f;

    // Step the simulation a few steps
    for (int i=0; i < 1000; i++) {

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
