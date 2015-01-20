# libpicam - source files

# Source and header files
set (SOURCE
	 picam.cpp
	 picam_c.cpp
)
set (HEADERS
	 ../include/picam.h
)

# Compile as a static library
add_library (picam STATIC ${HEADERS} ${SOURCE})

# Link to the GCC atomic library
target_link_libraries(picam LINK_PUBLIC atomic)