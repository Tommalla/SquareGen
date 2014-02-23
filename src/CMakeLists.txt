set(COMMON_HEADERS
	func.hpp
	types.hpp
)

set(COMMON_SOURCES
	func.cpp
)

set(NMCS_HEADERS
	NMCS.hpp
)

set(NMCS_SOURCES
	NMCS.cpp
)

set(NRPA_HEADERS
	NRPA.hpp
)

set(NRPA_SOURCES
	NRPA.cpp
)

set(NMCS_PROGRAM
	${COMMON_HEADERS}
	${COMMON_SOURCES}
	${NMCS_HEADERS}
	${NMCS_SOURCES}
	genNMCS.cpp
)

add_executable(genNMCS ${NMCS_PROGRAM})
add_executable(countTest countTest.cpp ${COMMON_HEADERS} ${COMMON_SOURCES})
add_executable(NMCSTest NMCSTest.cpp ${COMON_HEADERS} ${COMMON_SOURCES} ${NMCS_HEADERS} ${NMCS_SOURCES})
add_executable(NRPATest NRPATest.cpp ${COMMON_HEADERS} ${COMMON_SOURCES} ${NRPA_HEADERS} ${NRPA_SOURCES})