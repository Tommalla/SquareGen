set(HEADERS
	func.hpp
	types.hpp
	NMCS.hpp
	NRPA.hpp
)

set(SOURCES
	func.cpp
	NMCS.cpp
	NRPA.cpp
	main.cpp
)

add_executable(squaregen ${SOURCES})
add_executable(countTest countTest.cpp func.hpp func.cpp)
add_executable(NMCSTest NMCSTest.cpp func.hpp func.cpp NMCS.hpp NMCS.cpp)
add_executable(NRPATest NRPATest.cpp func.hpp func.cpp NRPA.hpp NRPA.cpp)