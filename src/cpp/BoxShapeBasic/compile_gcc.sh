#!/bin/sh

# compile_gcc.sh
#
# Compile the project with the object files
# in 'usr/obj' using g++.
#
# 2021/12/02

# Create object file of Main.cpp
g++ -c -std=c++11 Main.cpp -I ../../../ext/reactphysics3d/include -o Main.o

# Create executable
g++ -std=c++11 \
Main.o \
"../../../usr/obj/body/CollisionBody.o" \
"../../../usr/obj/body/RigidBody.o" \
"../../../usr/obj/collision/broadphase/DynamicAABBTree.o" \
"../../../usr/obj/collision/narrowphase/CollisionDispatch.o" \
"../../../usr/obj/collision/narrowphase/GJK/VoronoiSimplex.o" \
"../../../usr/obj/collision/narrowphase/GJK/GJKAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/SAT/SATAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/SphereVsSphereAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/CapsuleVsCapsuleAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/SphereVsCapsuleAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.o" \
"../../../usr/obj/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgoritihm.o" \
"../../../usr/obj/collision/narrowphase/NarrowPhaseInput.o" \
"../../../usr/obj/collision/narrowphase/NarrowPhaseInfoBatch.o" \
"../../../usr/obj/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.o" \
"../../../usr/obj/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.o" \
"../../../usr/obj/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.o" \
"../../../usr/obj/collision/shapes/AABB.o" \
"../../../usr/obj/collision/shapes/ConvexShape.o" \
"../../../usr/obj/collision/shapes/ConvexPolyhedronShape.o" \
"../../../usr/obj/collision/shapes/ConcaveShape.o" \
"../../../usr/obj/collision/shapes/BoxShape.o" \
"../../../usr/obj/collision/shapes/CapsuleShape.o" \
"../../../usr/obj/collision/shapes/CollisionShape.o" \
"../../../usr/obj/collision/shapes/ConvexMeshShape.o" \
"../../../usr/obj/collision/shapes/SphereShape.o" \
"../../../usr/obj/collision/shapes/TriangleShape.o" \
"../../../usr/obj/collision/shapes/ConcaveMeshShape.o" \
"../../../usr/obj/collision/shapes/HeightFieldShape.o" \
"../../../usr/obj/collision/RaycastInfo.o" \
"../../../usr/obj/collision/Collider.o" \
"../../../usr/obj/collision/TriangleVertexArray.o" \
"../../../usr/obj/collision/PolygonVertexArray.o" \
"../../../usr/obj/collision/TriangleMesh.o" \
"../../../usr/obj/collision/PolyhedronMesh.o" \
"../../../usr/obj/collision/HalfEdgeStructure.o" \
"../../../usr/obj/collision/ContactManifold.o" \
"../../../usr/obj/constraint/BallAndSocketJoint.o" \
"../../../usr/obj/constraint/ContactPoint.o" \
"../../../usr/obj/constraint/FixedJoint.o" \
"../../../usr/obj/constraint/HingeJoint.o" \
"../../../usr/obj/constraint/Joint.o" \
"../../../usr/obj/constraint/SliderJoint.o" \
"../../../usr/obj/engine/PhysicsCommon.o" \
"../../../usr/obj/systems/ConstraintSolverSystem.o" \
"../../../usr/obj/systems/ContactSolverSystem.o" \
"../../../usr/obj/systems/DynamicsSystem.o" \
"../../../usr/obj/systems/CollisionDetectionSystem.o" \
"../../../usr/obj/systems/SolveBallAndSocketJointSystem.o" \
"../../../usr/obj/systems/SolveFixedJointSystem.o" \
"../../../usr/obj/systems/SolveHingeJointSystem.o" \
"../../../usr/obj/systems/SolveSliderJointSystem.o" \
"../../../usr/obj/engine/PhysicsWorld.o" \
"../../../usr/obj/engine/Island.o" \
"../../../usr/obj/engine/Material.o" \
"../../../usr/obj/engine/Timer.o" \
"../../../usr/obj/engine/OverlappingPairs.o" \
"../../../usr/obj/engine/Entity.o" \
"../../../usr/obj/engine/EntityManager.o" \
"../../../usr/obj/systems/BroadPhaseSystem.o" \
"../../../usr/obj/components/Components.o" \
"../../../usr/obj/components/CollisionBodyComponents.o" \
"../../../usr/obj/components/RigidBodyComponents.o" \
"../../../usr/obj/components/TransformComponents.o" \
"../../../usr/obj/components/ColliderComponents.o" \
"../../../usr/obj/components/JointComponents.o" \
"../../../usr/obj/components/BallAndSocketJointComponents.o" \
"../../../usr/obj/components/FixedJointComponents.o" \
"../../../usr/obj/components/HingeJointComponents.o" \
"../../../usr/obj/components/SliderJointComponents.o" \
"../../../usr/obj/collision/CollisionCallback.o" \
"../../../usr/obj/collision/OverlapCallback.o" \
"../../../usr/obj/mathematics/mathematics_functions.o" \
"../../../usr/obj/mathematics/Matrix2x2.o" \
"../../../usr/obj/mathematics/Matrix3x3.o" \
"../../../usr/obj/mathematics/Quaternion.o" \
"../../../usr/obj/mathematics/Transform.o" \
"../../../usr/obj/mathematics/Vector2.o" \
"../../../usr/obj/mathematics/Vector3.o" \
"../../../usr/obj/memory/PoolAllocator.o" \
"../../../usr/obj/memory/SingleFrameAllocator.o" \
"../../../usr/obj/memory/HeapAllocator.o" \
"../../../usr/obj/memory/MemoryManager.o" \
"../../../usr/obj/utils/Profiler.o" \
"../../../usr/obj/utils/DefaultLogger.o" \
"../../../usr/obj/utils/DebugRenderer.o" \
-o BoxShapeBasic

# Remove object file
rm Main.o
