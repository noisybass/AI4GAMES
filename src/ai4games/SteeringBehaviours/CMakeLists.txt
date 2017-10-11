add_library(SteeringBehaviours SteeringBehaviours.cpp Vehicle.cpp)

target_include_directories(SteeringBehaviours PUBLIC "${CMAKE_SOURCE_DIR}/include/ai4games")