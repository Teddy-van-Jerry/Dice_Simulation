#!/bin/sh

# compile_rp3d_clang.sh
#
# Compile ReactPhysics3d into object file using clang++.
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
clang++ -w -c "../ext/reactphysics3d/src/body/CollisionBody.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/body/CollisionBody.o"
clang++ -w -c "../ext/reactphysics3d/src/body/RigidBody.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/body/RigidBody.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/broadphase/DynamicAABBTree.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/broadphase/DynamicAABBTree.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CollisionDispatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CollisionDispatch.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/GJK/VoronoiSimplex.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/GJK/VoronoiSimplex.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/GJK/GJKAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/GJK/GJKAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SAT/SATAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SAT/SATAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsSphereAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsSphereAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsCapsuleAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsCapsuleAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsCapsuleAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsCapsuleAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsConvexPolyhedronAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsConvexPolyhedronAlgorithm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgorithm.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/ConvexPolyhedronVsConvexPolyhedronAlgoritihm.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/NarrowPhaseInput.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/NarrowPhaseInput.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/NarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/NarrowPhaseInfoBatch.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsSphereNarrowPhaseInfoBatch.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/CapsuleVsCapsuleNarrowPhaseInfoBatch.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/narrowphase/SphereVsCapsuleNarrowPhaseInfoBatch.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/AABB.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/AABB.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexPolyhedronShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexPolyhedronShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConcaveShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConcaveShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/BoxShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/BoxShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/CapsuleShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/CapsuleShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/CollisionShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/CollisionShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConvexMeshShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConvexMeshShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/SphereShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/SphereShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/TriangleShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/TriangleShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/ConcaveMeshShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/ConcaveMeshShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/shapes/HeightFieldShape.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/shapes/HeightFieldShape.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/RaycastInfo.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/RaycastInfo.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/Collider.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/Collider.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/TriangleVertexArray.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/TriangleVertexArray.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/PolygonVertexArray.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/PolygonVertexArray.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/TriangleMesh.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/TriangleMesh.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/PolyhedronMesh.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/PolyhedronMesh.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/HalfEdgeStructure.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/HalfEdgeStructure.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/ContactManifold.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/ContactManifold.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/BallAndSocketJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/BallAndSocketJoint.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/ContactPoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/ContactPoint.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/FixedJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/FixedJoint.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/HingeJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/HingeJoint.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/Joint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/Joint.o"
clang++ -w -c "../ext/reactphysics3d/src/constraint/SliderJoint.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/constraint/SliderJoint.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/PhysicsCommon.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/PhysicsCommon.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/ConstraintSolverSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/ConstraintSolverSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/ContactSolverSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/ContactSolverSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/DynamicsSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/DynamicsSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/CollisionDetectionSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/CollisionDetectionSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/SolveBallAndSocketJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveBallAndSocketJointSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/SolveFixedJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveFixedJointSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/SolveHingeJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveHingeJointSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/SolveSliderJointSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/SolveSliderJointSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/PhysicsWorld.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/PhysicsWorld.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/Island.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Island.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/Material.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Material.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/Timer.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Timer.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/OverlappingPairs.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/OverlappingPairs.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/Entity.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/Entity.o"
clang++ -w -c "../ext/reactphysics3d/src/engine/EntityManager.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/engine/EntityManager.o"
clang++ -w -c "../ext/reactphysics3d/src/systems/BroadPhaseSystem.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/systems/BroadPhaseSystem.o"
clang++ -w -c "../ext/reactphysics3d/src/components/Components.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/Components.o"
clang++ -w -c "../ext/reactphysics3d/src/components/CollisionBodyComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/CollisionBodyComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/RigidBodyComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/RigidBodyComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/TransformComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/TransformComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/ColliderComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/ColliderComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/JointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/JointComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/BallAndSocketJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/BallAndSocketJointComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/FixedJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/FixedJointComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/HingeJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/HingeJointComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/components/SliderJointComponents.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/components/SliderJointComponents.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/CollisionCallback.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/CollisionCallback.o"
clang++ -w -c "../ext/reactphysics3d/src/collision/OverlapCallback.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/collision/OverlapCallback.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/mathematics_functions.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/mathematics_functions.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Matrix2x2.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Matrix2x2.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Matrix3x3.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Matrix3x3.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Quaternion.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Quaternion.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Transform.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Transform.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Vector2.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Vector2.o"
clang++ -w -c "../ext/reactphysics3d/src/mathematics/Vector3.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/mathematics/Vector3.o"
clang++ -w -c "../ext/reactphysics3d/src/memory/PoolAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/PoolAllocator.o"
clang++ -w -c "../ext/reactphysics3d/src/memory/SingleFrameAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/SingleFrameAllocator.o"
clang++ -w -c "../ext/reactphysics3d/src/memory/HeapAllocator.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/HeapAllocator.o"
clang++ -w -c "../ext/reactphysics3d/src/memory/MemoryManager.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/memory/MemoryManager.o"
clang++ -w -c "../ext/reactphysics3d/src/utils/Profiler.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/Profiler.o"
clang++ -w -c "../ext/reactphysics3d/src/utils/DefaultLogger.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/DefaultLogger.o"
clang++ -w -c "../ext/reactphysics3d/src/utils/DebugRenderer.cpp" -std=c++11 -I ../ext/reactphysics3d/include -o "obj/utils/DebugRenderer.o"
