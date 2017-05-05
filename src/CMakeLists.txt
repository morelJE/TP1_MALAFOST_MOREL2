project(libprng)
set(SOURCES
	Dvector.cpp GenerateurNombreAleatoire.cpp
)
add_library(${PROJECT_NAME} ${SOURCES})

