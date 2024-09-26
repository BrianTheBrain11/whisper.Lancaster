if (WHISPER_SDL2)
    set (TARGET tbs-whisper-api)

    add_library(${TARGET} 
    tbs-whisper-api.cpp
    tbs-whisper-api.h
    )

    include(DefaultTargetOptions)

    target_link_libraries(${TARGET} PRIVATE common common-sdl whisper ${CMAKE_THREAD_LIBS_INIT})
    
    set(COPY_OUTPUT_LOCATION "%HOMEDRIVE%%HOMEPATH%/Saved Games/DCS.openbeta/Mods/aircraft/Project-Lancaster/bin/")
    add_custom_command(
        TARGET ${TARGET}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${TARGET}> ${COPY_OUTPUT_LOCATION}
        COMMENT "Copying output dll to ${COPY_OUTPUT_LOCATION}"
    )
endif()