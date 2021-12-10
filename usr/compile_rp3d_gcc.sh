#!/bin/sh

# compile_rp3d_gcc.sh
#
# Compile ReactPhysics3d into object file using g++.
# Object files are in folder 'obj'.
# Warnings are disabled.
#
# Teddy van Jerry
# 2021/09/30

# create dirs
mkdir obj
cd obj
mkdir body
mkdir collision
mkdir collision/broadphase
mkdir collision/narrowphase
mkdir collision/narrowphase/GJK
mkdir collision/narrowphase/SAT
mkdir collision/shapes
mkdir constraint
mkdir engine
mkdir systems
mkdir components
mkdir mathematics
mkdir memory
mkdir utils
cd ..

# compile object files
g++ -w -c "../ext/reactphysics3d/src/body/CollisionBody.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/body/CollisionBody.o"
g++ -w -c "../ext/reactphysics3d/src/body/RigidBody.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/body/RigidBody.o"
g++ -w -c "../ext/reactphysics3d/src/collision/broadphase/DynamicAABBTree.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/broadphase/DynamicAABBTree.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CollisionDispatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CollisionDispatch.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/GJK/VoronoiSimplex.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/GJK/VoronoiSimplex.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/GJK/GJKAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/GJK/GJKAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SAT/SATAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SAT/SATAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsSphereAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsSphereAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsCapsuleAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsCapsuleAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsCapsuleAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsCapsuleAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgoritihm.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/NarrowPhaseInput.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/NarrowPhaseInput.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/NarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/NarrowPhaseInfoBatch.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.o"
g++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/AABB.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/AABB.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexPolyhedronShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexPolyhedronShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConcaveShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConcaveShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/BoxShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/BoxShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/CapsuleShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/CapsuleShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/CollisionShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/CollisionShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexMeshShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexMeshShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/SphereShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/SphereShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/TriangleShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/TriangleShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConcaveMeshShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConcaveMeshShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/shapes/HeightFieldShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/HeightFieldShape.o"
g++ -w -c "../ext/reactphysics3d/src/collision/RaycastInfo.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/RaycastInfo.o"
g++ -w -c "../ext/reactphysics3d/src/collision/Collider.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/Collider.o"
g++ -w -c "../ext/reactphysics3d/src/collision/TriangleVertexArray.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/TriangleVertexArray.o"
g++ -w -c "../ext/reactphysics3d/src/collision/PolygonVertexArray.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/PolygonVertexArray.o"
g++ -w -c "../ext/reactphysics3d/src/collision/TriangleMesh.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/TriangleMesh.o"
g++ -w -c "../ext/reactphysics3d/src/collision/PolyhedronMesh.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/PolyhedronMesh.o"
g++ -w -c "../ext/reactphysics3d/src/collision/HalfEdgeStructure.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/HalfEdgeStructure.o"
g++ -w -c "../ext/reactphysics3d/src/collision/ContactManifold.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/ContactManifold.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/BallAndSocketJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/BallAndSocketJoint.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/ContactPoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/ContactPoint.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/FixedJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/FixedJoint.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/HingeJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/HingeJoint.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/Joint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/Joint.o"
g++ -w -c "../ext/reactphysics3d/src/constraint/SliderJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/SliderJoint.o"
g++ -w -c "../ext/reactphysics3d/src/engine/PhysicsCommon.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/PhysicsCommon.o"
g++ -w -c "../ext/reactphysics3d/src/systems/ConstraintSolverSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/ConstraintSolverSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/ContactSolverSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/ContactSolverSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/DynamicsSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/DynamicsSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/CollisionDetectionSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/CollisionDetectionSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/SolveBallAndSocketJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveBallAndSocketJointSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/SolveFixedJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveFixedJointSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/SolveHingeJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveHingeJointSystem.o"
g++ -w -c "../ext/reactphysics3d/src/systems/SolveSliderJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveSliderJointSystem.o"
g++ -w -c "../ext/reactphysics3d/src/engine/PhysicsWorld.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/PhysicsWorld.o"
g++ -w -c "../ext/reactphysics3d/src/engine/Island.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Island.o"
g++ -w -c "../ext/reactphysics3d/src/engine/Material.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Material.o"
g++ -w -c "../ext/reactphysics3d/src/engine/Timer.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Timer.o"
g++ -w -c "../ext/reactphysics3d/src/engine/OverlappingPairs.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/OverlappingPairs.o"
g++ -w -c "../ext/reactphysics3d/src/engine/Entity.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Entity.o"
g++ -w -c "../ext/reactphysics3d/src/engine/EntityManager.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/EntityManager.o"
g++ -w -c "../ext/reactphysics3d/src/systems/BroadPhaseSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/BroadPhaseSystem.o"
g++ -w -c "../ext/reactphysics3d/src/components/Components.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/Components.o"
g++ -w -c "../ext/reactphysics3d/src/components/CollisionBodyComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/CollisionBodyComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/RigidBodyComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/RigidBodyComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/TransformComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/TransformComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/ColliderComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/ColliderComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/JointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/JointComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/BallAndSocketJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/BallAndSocketJointComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/FixedJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/FixedJointComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/HingeJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/HingeJointComponents.o"
g++ -w -c "../ext/reactphysics3d/src/components/SliderJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/SliderJointComponents.o"
g++ -w -c "../ext/reactphysics3d/src/collision/CollisionCallback.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/CollisionCallback.o"
g++ -w -c "../ext/reactphysics3d/src/collision/OverlapCallback.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/OverlapCallback.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/mathematics_functions.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/mathematics_functions.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Matrix2x2.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Matrix2x2.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Matrix3x3.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Matrix3x3.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Quaternion.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Quaternion.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Transform.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Transform.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Vector2.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Vector2.o"
g++ -w -c "../ext/reactphysics3d/src/mathematics/Vector3.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Vector3.o"
g++ -w -c "../ext/reactphysics3d/src/memory/PoolAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/PoolAllocator.o"
g++ -w -c "../ext/reactphysics3d/src/memory/SingleFrameAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/SingleFrameAllocator.o"
g++ -w -c "../ext/reactphysics3d/src/memory/HeapAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/HeapAllocator.o"
g++ -w -c "../ext/reactphysics3d/src/memory/MemoryManager.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/MemoryManager.o"
g++ -w -c "../ext/reactphysics3d/src/utils/Profiler.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/Profiler.o"
g++ -w -c "../ext/reactphysics3d/src/utils/DefaultLogger.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/DefaultLogger.o"
g++ -w -c "../ext/reactphysics3d/src/utils/DebugRenderer.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/DebugRenderer.o"
