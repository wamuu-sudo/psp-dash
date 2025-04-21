cmake_minimum_required(VERSION 3.11)

project(psp-dash)

add_executable(${PROJECT_NAME}
    main.c
    gfx.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pspdebug
    pspdisplay
    pspgu
    pspge
)

# Crée le EBOOT.PBP automatiquement
create_pbp_file(
    TARGET ${PROJECT_NAME}
    TITLE "PSP-Dash"
    VERSION 0.2
)

