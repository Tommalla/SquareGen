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

target_link_libraries(NMCS common)
target_link_libraries(NRPA common)
target_link_libraries(BeamNRPA NRPA common)

add_executable(genNMCS genNMCS.cpp ${COMMON_HEADERS} ${NMCS_HEADERS})
target_link_libraries(genNMCS NMCS)

add_executable(genNRPA genNRPA.cpp ${COMMON_HEADERS} ${NRPA_HEADERS})
target_link_libraries(genNRPA NRPA)

add_executable(genBeamNRPA genBeamNRPA.cpp ${COMMON_HEADERS} ${BEAM_NRPA_HEADERS})
target_link_libraries(genBeamNRPA BeamNRPA)

add_executable(countTest countTest.cpp ${COMMON_HEADERS})
target_link_libraries(countTest common)

add_executable(NMCSTest NMCSTest.cpp ${COMON_HEADERS} ${NMCS_HEADERS})
target_link_libraries(NMCSTest NMCS)

add_executable(NRPATest NRPATest.cpp ${COMMON_HEADERS} ${NRPA_HEADERS})
target_link_libraries(NRPATest NRPA)

add_executable(countSquares countSquares.cpp ${COMMON_HEADERS})
target_link_libraries(countSquares common)

add_executable(BeamNRPATest BeamNRPATest.cpp ${BEAM_NRPA_HEADERS} ${COMMON_HEADERS} ${NRPA_HEADERS})
target_link_libraries(BeamNRPATest BeamNRPA)