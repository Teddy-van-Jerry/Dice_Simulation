// Converted by Dice Simulation 0.1.1 at 2021-12-19 08:54:53 UTC.
// Website: https://dice.teddy-van-jerry.org
// GitHub Repo: https://github.com/Teddy-van-Jerry/Dice_Simulation

#include "ds_core.ds-h"
using namespace ds;

const char* ds_version = "0.0.4";
double g = 9.81;

void foo1() {
    std::cout << "foo1" << std::endl;
}

void foo2() {
    std::cout << "foo2" << std::endl;
}


int main(int argc, char* argv[]) {
    // ====== floor ====== //
    PhysicsCommon physicsCommon;
    PhysicsWorld* world = physicsCommon.createPhysicsWorld();
    world->setGravity(Vector3(0, -g, 0));
    BoxShape* floor_shape = physicsCommon.createBoxShape(Vector3(1000000, 1, 1000000));
    RigidBody* floor = world->createRigidBody(Transform(Vector3(0, -1, 0), Quaternion::identity()));
    floor->setType(BodyType::STATIC);
    floor->addCollider(floor_shape, Transform::identity());

    // ====== DS DICE: BoxDice ====== //
    RigidBody* BoxDice_body = world->createRigidBody(Transform(Vector3(0, 2, 0), normalQuaternion()));
    BoxShape* BoxDice_shape = physicsCommon.createBoxShape(Vector(4, 2, 1));
    BoxDice_body->addCollider(BoxDice_shape, Transform::identity());
    BoxDice_body->setLinearVelocity(Vector3(0, 0, 0));
    BoxDice_body->setLinearDamping(1.2);
    BoxDice_body->getCollider(0)->getMaterial().setFrictionCoefficient(0.2);

    // ====== DS DICE: CylinderDice ====== //
    RigidBody* CylinderDice_body = world->createRigidBody(Transform(Vector3(0, 2, 0), normalQuaternion()));
    const int CylinderDice_sides = ;
    const float CylinderDice_R = 4;
    const float CylinderDice_H = 2;
    float CylinderDice_vertices[6 * CylinderDice_sides];
    for (int i = 0; i != CylinderDice_sides; i++) {
        CylinderDice_vertices[3 * i] = -CylinderDice_R * std::cos(2 * 3.14159265358979 * i / CylinderDice_sides);
        CylinderDice_vertices[3 * i + 1] = -CylinderDice_H / 2;
        CylinderDice_vertices[3 * i + 2] = CylinderDice_R * std::sin(2 * 3.14159265358979 * i / CylinderDice_sides);
        CylinderDice_vertices[3 * (i + CylinderDice_sides)] = CylinderDice_vertices[3 * i];
        CylinderDice_vertices[3 * (i + CylinderDice_sides) + 1] = CylinderDice_H / 2;
        CylinderDice_vertices[3 * (i + CylinderDice_sides) + 2] = CylinderDice_vertices[3 * i + 2];
    }
    int CylinderDice_indices[6 * CylinderDice_sides];
    for (int i = 0; i != CylinderDice_sides - 1; i++) {
        CylinderDice_indices[4 * i    ] = i;
        CylinderDice_indices[4 * i + 1] = i + 1;
        CylinderDice_indices[4 * i + 2] = CylinderDice_sides + i + 1;
        CylinderDice_indices[4 * i + 3] = CylinderDice_sides + i;
        CylinderDice_indices[4 * CylinderDice_sides + i] = CylinderDice_sides - i - 1;
        CylinderDice_indices[5 * CylinderDice_sides + i] = CylinderDice_sides + i;
    }
    CylinderDice_indices[4 * CylinderDice_sides - 4] = CylinderDice_sides - 1;
    CylinderDice_indices[4 * CylinderDice_sides - 3] = 0;
    CylinderDice_indices[4 * CylinderDice_sides - 2] = CylinderDice_sides;
    CylinderDice_indices[4 * CylinderDice_sides - 1] = 2 * CylinderDice_sides - 1;
    CylinderDice_indices[5 * CylinderDice_sides - 1] = 0;
    CylinderDice_indices[6 * CylinderDice_sides - 1] = 2 * CylinderDice_sides - 1;
    PolygonVertexArray::PolygonFace CylinderDice_polygonFaces[CylinderDice_sides + 2];
    for (int f = 0; f != CylinderDice_sides; f++) {
        CylinderDice_polygonFaces[f].indexBase = f * 4;
        CylinderDice_polygonFaces[f].nbVertices = 4;
    }
    CylinderDice_polygonFaces[CylinderDice_sides].indexBase = CylinderDice_sides * 4;
    CylinderDice_polygonFaces[CylinderDice_sides].nbVertices = CylinderDice_sides;
    CylinderDice_polygonFaces[CylinderDice_sides + 1].indexBase = CylinderDice_sides * 5;
    CylinderDice_polygonFaces[CylinderDice_sides + 1].nbVertices = CylinderDice_sides;
    PolygonVertexArray* CylinderDice_polygonVertexArray = new PolygonVertexArray(
        2 * CylinderDice_sides, CylinderDice_vertices, 3 * sizeof(float), CylinderDice_indices,
        sizeof(int), CylinderDice_sides + 2, CylinderDice_polygonFaces,
        PolygonVertexArray::VertexDataType::VERTEX_FLOAT_TYPE, PolygonVertexArray::IndexDataType::INDEX_INTEGER_TYPE);
    PolyhedronMesh* CylinderDice_polyhedronMesh = physicsCommon.createPolyhedronMesh(CylinderDice_polygonVertexArray);
    ConvexMeshShape*CylinderDice_shape = physicsCommon.createConvexMeshShape(CylinderDice_polyhedronMesh);
    CylinderDice_body->addCollider(CylinderDice_shape, Transform::identity());
    CylinderDice_body->setLinearVelocity(Vector3(0, 0, 0));
    CylinderDice_body->setLinearDamping(1.2);
    CylinderDice_body->getCollider(0)->getMaterial().setFrictionCoefficient(0.2);

    for (int i = 0; i != 100; i++) {
        std::cout << "Round " << i << ":" << std::endl;
        // ====== DS TASK: simu ====== //
        const float timeStep_0 = 1.0f / 60.0f;
        for (int i = 0; i < int((300000.0f) / (1.0f / 60.0f)); i++) {
            world->update(timeStep_0);
            const Transform& transform =  CylinderDice_body->getTransform();
            const Vector3& position = transform.getPosition();
            const Vector3& velocity =  CylinderDice_body->getLinearVelocity();
            const Vector3& angular_velocity =  CylinderDice_body->getAngularVelocity();
            const Quaternion& orientation = transform.getOrientation();
            if (true) {
                std::cout << "Position: ";
                std::cout << "(" << position.x << ", " << position.y << ", " << position.z << ")";
                std::cout << '\t';
                std::cout << "Velocity: ";
                std::cout << "(" << velocity.x << ", " << velocity.y << ", " << velocity.z << ")";
                std::cout << std::endl;
            }
            if (velocity.length() <= 1E-8 && angular_velocity.length() <= 1E-8) break;
        }

    }
    std::cout << "End of process" << std::endl;
    return 0;
}

