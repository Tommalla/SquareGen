set(COMMON_HEADERS
	func.hpp
	types.hpp
)

set(COMMON_SOURCES
	func.cpp
)

set(ABSTRACT_MCS_HEADERS
	AbstractMCS.hpp
)

set(ABSTRACT_MCS_SOURCES
	AbstractMCS.cpp
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

set(BEAM_NRPA_HEADERS
	BeamNRPA.hpp
)

set(BEAM_NRPA_SOURCES
	BeamNRPA.cpp
)

add_library(common ${COMMON_HEADERS} ${COMMON_SOURCES})
add_library(NMCS ${NMCS_HEADERS} ${COMMON_HEADERS} ${NMCS_SOURCES})
add_library(NRPA ${NRPA_HEADERS} ${COMMON_HEADERS} ${NRPA_SOURCES})
add_library(BeamNRPA ${NRPA_HEADERS} ${COMMON_HEADERS} ${BEAM_NRPA_HEADERS} ${BEAM_NRPA_SOURCES})
add_library(AbstractMCS ${ABSTRACT_MCS_HEADERS} ${ABSTRACT_MCS_SOURCES})

target_link_libraries(NMCS AbstractMCS common)
target_link_libraries(NRPA AbstractMCS common)
target_link_libraries(BeamNRPA NRPA common)

add_executable(squareGen squareGen.cpp ${COMMON_HEADERS} ${NMCS_HEADERS} ${NRPA_HEADERS} ${BEAM_NRPA_HEADERS})
target_link_libraries(squareGen NMCS NRPA BeamNRPA)

add_executable(countSquares countSquares.cpp ${COMMON_HEADERS})
target_link_libraries(countSquares common)

add_executable(NMCSTest NMCSTest.cpp ${COMON_HEADERS} ${NMCS_HEADERS})
target_link_libraries(NMCSTest NMCS)

add_executable(NRPATest NRPATest.cpp ${COMMON_HEADERS} ${NRPA_HEADERS})
target_link_libraries(NRPATest NRPA)

add_executable(BeamNRPATest BeamNRPATest.cpp ${BEAM_NRPA_HEADERS} ${COMMON_HEADERS} ${NRPA_HEADERS})
target_link_libraries(BeamNRPATest BeamNRPA)

add_executable(countTest countTest.cpp ${COMMON_HEADERS})
target_link_libraries(countTest common)