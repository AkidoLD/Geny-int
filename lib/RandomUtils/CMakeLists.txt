# Définir la bibliothèque partagée
add_library(RandomUtils SHARED
    RandomUtils.cpp
)

# Inclure les headers de RandomUtils pour qu'ils soient visibles par le projet principal
target_include_directories(RandomUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
