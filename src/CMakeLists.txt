set(HEADERS
	func.hpp
	NMCS.hpp
)

set(SOURCES
	func.cpp
	NMCS.cpp
	main.cpp
)

add_executable(squaregen ${SOURCES})
add_executable(countTest countTest.cpp func.hpp func.cpp)
add_executable(NMCSTest NMCSTest.cpp func.hpp func.cpp NMCS.hpp NMCS.cpp)