# Set the project name
project (Objects)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
	src/TransformationMonoid.cpp
	src/BaseObject.cpp
	src/FiniteAutomaton.cpp
	src/Regex.cpp
	src/Language.cpp
	src/Grammar.cpp
	src/AlphabetSymbol.cpp
    src/Logger.cpp)

# Add a library with the above sources
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	Fraction
	AutomatonToImage
)