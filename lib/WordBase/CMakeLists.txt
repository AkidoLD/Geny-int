# Définir la bibliothèque partagée
add_library(WordBase SHARED
    WordBase.cpp
)

# Inclure les headers de RandomUtils pour qu'ils soient visibles par le projet principal
target_include_directories(WordBase PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
