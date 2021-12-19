#!/bin/sh

# compile_CylinderP.sh
#
# Compile the project with the object files
# in 'usr/obj' using clang++.
#
# 2021/12/18

# Create object file of Main.cpp
clang++ -c -o3 -std=c++11 CylinderP.cpp -I../../include -o CylinderP.o

# Create executable
clang++ -o3 -std=c++11 \
CylinderP.o \
"../obj/ds/ds_core.o" \
"../obj/body/CollisionBody.o" \
"../obj/body/RigidBody.o" \
"../obj/collision/broadphase/DynamicAABBTree.o" \
"../obj/collision/narrowphase/CollisionDispatch.o" \
"../obj/collision/narrowphase/GJK/VoronoiSimplex.o" \
"../obj/collision/narrowphase/GJK/GJKAlgorithm.o" \
"../obj/collision/narrowphase/SAT/SATAlgorithm.o" \
"../obj/collision/narrowphase/SphereVsSphereAlgorithm.o" \
"../obj/collision/narrowphase/CapsuleVsCapsuleAlgorithm.o" \
"../obj/collision/narrowphase/SphereVsCapsuleAlgorithm.o" \
"../obj/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.o" \
"../obj/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.o" \
"../obj/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgoritihm.o" \
"../obj/collision/narrowphase/NarrowPhaseInput.o" \
"../obj/collision/narrowphase/NarrowPhaseInfoBatch.o" \
"../obj/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.o" \
"../obj/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.o" \
"../obj/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.o" \
"../obj/collision/shapes/AABB.o" \
"../obj/collision/shapes/ConvexShape.o" \
"../obj/collision/shapes/ConvexPolyhedronShape.o" \
"../obj/collision/shapes/ConcaveShape.o" \
"../obj/collision/shapes/BoxShape.o" \
"../obj/collision/shapes/CapsuleShape.o" \
"../obj/collision/shapes/CollisionShape.o" \
"../obj/collision/shapes/ConvexMeshShape.o" \
"../obj/collision/shapes/SphereShape.o" \
"../obj/collision/shapes/TriangleShape.o" \
"../obj/collision/shapes/ConcaveMeshShape.o" \
"../obj/collision/shapes/HeightFieldShape.o" \
"../obj/collision/RaycastInfo.o" \
"../obj/collision/Collider.o" \
"../obj/collision/TriangleVertexArray.o" \
"../obj/collision/PolygonVertexArray.o" \
"../obj/collision/TriangleMesh.o" \
"../obj/collision/PolyhedronMesh.o" \
"../obj/collision/HalfEdgeStructure.o" \
"../obj/collision/ContactManifold.o" \
"../obj/constraint/BallAndSocketJoint.o" \
"../obj/constraint/ContactPoint.o" \
"../obj/constraint/FixedJoint.o" \
"../obj/constraint/HingeJoint.o" \
"../obj/constraint/Joint.o" \
"../obj/constraint/SliderJoint.o" \
"../obj/engine/PhysicsCommon.o" \
"../obj/systems/ConstraintSolverSystem.o" \
"../obj/systems/ContactSolverSystem.o" \
"../obj/systems/DynamicsSystem.o" \
"../obj/systems/CollisionDetectionSystem.o" \
"../obj/systems/SolveBallAndSocketJointSystem.o" \
"../obj/systems/SolveFixedJointSystem.o" \
"../obj/systems/SolveHingeJointSystem.o" \
"../obj/systems/SolveSliderJointSystem.o" \
"../obj/engine/PhysicsWorld.o" \
"../obj/engine/Island.o" \
"../obj/engine/Material.o" \
"../obj/engine/Timer.o" \
"../obj/engine/OverlappingPairs.o" \
"../obj/engine/Entity.o" \
"../obj/engine/EntityManager.o" \
"../obj/systems/BroadPhaseSystem.o" \
"../obj/components/Components.o" \
"../obj/components/CollisionBodyComponents.o" \
"../obj/components/RigidBodyComponents.o" \
"../obj/components/TransformComponents.o" \
"../obj/components/ColliderComponents.o" \
"../obj/components/JointComponents.o" \
"../obj/components/BallAndSocketJointComponents.o" \
"../obj/components/FixedJointComponents.o" \
"../obj/components/HingeJointComponents.o" \
"../obj/components/SliderJointComponents.o" \
"../obj/collision/CollisionCallback.o" \
"../obj/collision/OverlapCallback.o" \
"../obj/mathematics/mathematics_functions.o" \
"../obj/mathematics/Matrix2x2.o" \
"../obj/mathematics/Matrix3x3.o" \
"../obj/mathematics/Quaternion.o" \
"../obj/mathematics/Transform.o" \
"../obj/mathematics/Vector2.o" \
"../obj/mathematics/Vector3.o" \
"../obj/memory/PoolAllocator.o" \
"../obj/memory/SingleFrameAllocator.o" \
"../obj/memory/HeapAllocator.o" \
"../obj/memory/MemoryManager.o" \
"../obj/utils/Profiler.o" \
"../obj/utils/DefaultLogger.o" \
"../obj/utils/DebugRenderer.o" \
-o ../bin/CylinderP

# Remove object file
rm CylinderP.o
