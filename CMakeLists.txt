cmake_minimum_required(VERSION 3.16)  # 3.30.x n'existe pas encore

project(Geny LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilation warnings si on est en Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra)
endif()

# Trouve Qt6 et son module Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Fichiers sources
file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

# Crée l'exécutable
add_executable(Geny-int ${SRC} ${HEADERS})

# Dossier d'includes
target_include_directories(Geny-int PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Active la gestion automatique des MOC (Meta Object Compiler) pour les signaux/slots
set_target_properties(Geny-int PROPERTIES AUTOMOC ON)

# Lie Qt6::Widgets à ton exécutable
target_link_libraries(Geny-int PRIVATE Qt6::Widgets)
