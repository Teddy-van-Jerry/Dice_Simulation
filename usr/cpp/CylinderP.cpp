// Converted by Dice Simulation 0.1.1 at 2021-12-18 17:38:26 UTC.
// Website: https://dice.teddy-van-jerry.org
// GitHub Repo: https://github.com/Teddy-van-Jerry/Dice_Simulation

#define ori dice_body->getTransform().getOrientation()

#include "ds_core.ds-h"
#include <iomanip>
using namespace ds;

const char* version = "0.1.1";
double g = 9.81;
DSRandom r; // random engine


int main(int argc, char* argv[]) {
    // ====== floor ====== //
    PhysicsCommon physicsCommon;
    PhysicsWorld* world = physicsCommon.createPhysicsWorld();
    world->setGravity(Vector3(0, -g, 0));
    BoxShape* floor_shape = physicsCommon.createBoxShape(Vector3(1000000, 1, 1000000));
    RigidBody* floor = world->createRigidBody(Transform(Vector3(0, -1, 0), Quaternion::identity()));
    floor->setType(BodyType::STATIC);
    floor->addCollider(floor_shape, Transform::identity());


    for (double R_H = 0.5; R_H < 2.51; R_H += 0.1) {
        // ====== DS DICE: dice ====== //
        RigidBody* dice_body = world->createRigidBody(Transform(Vector3(0, 1, 0), normalQuaternion(0, 0, 0, 0)));
        const int dice_sides = 1000;
        const float dice_R = 4 * R_H;
        const float dice_H = 4;
        float dice_vertices[6 * dice_sides];
        for (int i = 0; i != dice_sides; i++) {
            dice_vertices[3 * i] = -dice_R * std::cos(2 * 3.14159265358979 * i / dice_sides);
            dice_vertices[3 * i + 1] = -dice_H / 2;
            dice_vertices[3 * i + 2] = dice_R * std::sin(2 * 3.14159265358979 * i / dice_sides);
            dice_vertices[3 * (i + dice_sides)] = dice_vertices[3 * i];
            dice_vertices[3 * (i + dice_sides) + 1] = dice_H / 2;
            dice_vertices[3 * (i + dice_sides) + 2] = dice_vertices[3 * i + 2];
        }
        int dice_indices[6 * dice_sides];
        for (int i = 0; i != dice_sides - 1; i++) {
            dice_indices[4 * i    ] = i;
            dice_indices[4 * i + 1] = i + 1;
            dice_indices[4 * i + 2] = dice_sides + i + 1;
            dice_indices[4 * i + 3] = dice_sides + i;
            dice_indices[4 * dice_sides + i] = dice_sides - i - 1;
            dice_indices[5 * dice_sides + i] = dice_sides + i;
        }
        dice_indices[4 * dice_sides - 4] = dice_sides - 1;
        dice_indices[4 * dice_sides - 3] = 0;
        dice_indices[4 * dice_sides - 2] = dice_sides;
        dice_indices[4 * dice_sides - 1] = 2 * dice_sides - 1;
        dice_indices[5 * dice_sides - 1] = 0;
        dice_indices[6 * dice_sides - 1] = 2 * dice_sides - 1;
        PolygonVertexArray::PolygonFace dice_polygonFaces[dice_sides + 2];
        for (int f = 0; f != dice_sides; f++) {
            dice_polygonFaces[f].indexBase = f * 4;
            dice_polygonFaces[f].nbVertices = 4;
        }
        dice_polygonFaces[dice_sides].indexBase = dice_sides * 4;
        dice_polygonFaces[dice_sides].nbVertices = dice_sides;
        dice_polygonFaces[dice_sides + 1].indexBase = dice_sides * 5;
        dice_polygonFaces[dice_sides + 1].nbVertices = dice_sides;
        PolygonVertexArray* dice_polygonVertexArray = new PolygonVertexArray(
            2 * dice_sides, dice_vertices, 3 * sizeof(float), dice_indices,
            sizeof(int), dice_sides + 2, dice_polygonFaces,
            PolygonVertexArray::VertexDataType::VERTEX_FLOAT_TYPE, PolygonVertexArray::IndexDataType::INDEX_INTEGER_TYPE);
        PolyhedronMesh* dice_polyhedronMesh = physicsCommon.createPolyhedronMesh(dice_polygonVertexArray);
        ConvexMeshShape*dice_shape = physicsCommon.createConvexMeshShape(dice_polyhedronMesh);
        dice_body->addCollider(dice_shape, Transform::identity());
        dice_body->setLinearVelocity(Vector3(0, 0, 0));
        dice_body->setAngularVelocity(Vector3(0, 0, 0));
        dice_body->setLinearDamping(0);
        dice_body->setAngularDamping(0);
        dice_body->getCollider(0)->getMaterial().setBounciness(0);
        dice_body->getCollider(0)->getMaterial().setFrictionCoefficient(10);


        int TESTS = 1000;
        int P_occur = 0;
        for (int test = 0; test != TESTS; test++) {
            // ====== DS TASK: simu ====== //
            dice_body->setTransform(Transform(Vector3(0, 100, 0),  dice_body->getTransform().getOrientation()));
            dice_body->setTransform(Transform( dice_body->getTransform().getPosition(), normalQuaternion(r.normal(), r.normal(), r.normal(), r.uniform())));
            dice_body->setLinearVelocity(Vector3(0, 0, 0));
            dice_body->setAngularVelocity(Vector3(0, 0, 0));
            const float timeStep_0 =  1.0f / 120.0f;
            for (int i = 0; i < int((  10) / ( 1.0f / 120.0f)); i++) {
                world->update(timeStep_0);
                const Transform& transform =  dice_body->getTransform();
                const Vector3& position = transform.getPosition();
                const Vector3& velocity =  dice_body->getLinearVelocity();
                const Vector3& angular_velocity =  dice_body->getAngularVelocity();
                const Quaternion& orientation = transform.getOrientation();
                // std::cout << std::setw(7) << "t=" << float(i) / 60.0f << ": ";
                if ( false) {
                    std::cout << "pos:";
                    std::cout << "(" << position.x << ", " << position.y << ", " << position.z << ")";
                    std::cout << "\tv:";
                    std::cout << velocity.length();
                    std::cout << "\tori:";
                    std::cout << "(" << orientation.x << ", " << orientation.y << ", " << orientation.z << ", " << orientation.w << ")";
                    std::cout << std::endl;
                }
                if (velocity.length() <=  1E-8 && angular_velocity.length() <=  1E-8) break;
            }
            if (fabs(ori.x) > 0.01 && fabs(ori.y) > 0.01 && fabs(ori.z) > 0.01 && fabs(ori.w) > 0.01) P_occur++;
        }
        std::cout << (double)P_occur / TESTS << std::endl;
    }

    return 0;
}

