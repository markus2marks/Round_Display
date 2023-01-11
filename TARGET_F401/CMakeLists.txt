add_library(mbed-round-display INTERFACE)

target_include_directories(mbed-round-display
    INTERFACE
        .
)

target_sources(mbed-round-display
    	INTERFACE
	PeripheralPins.c
)