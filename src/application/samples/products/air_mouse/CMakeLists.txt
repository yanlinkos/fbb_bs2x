set(SOURCES_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/sle_air_mouse_with_dongle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/air_mouse_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/usb/air_mouse_usb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/timer/am_common_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic/vdt_codec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic/amic_voice.c
)

set(HEADER_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic
)

if(DEFINED CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
    set(SOURCES_LIST
        ${SOURCES_LIST}
        ${CMAKE_CURRENT_SOURCE_DIR}/dongle/sle_air_mouse_client/sle_air_mouse_client.c
        ${CMAKE_CURRENT_SOURCE_DIR}/dongle/radar/air_mouse_radar.c
    )
endif()

if(DEFINED CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
    set(SOURCES_LIST
        ${SOURCES_LIST}
        ${CMAKE_CURRENT_SOURCE_DIR}/mouse/sle_air_mouse_server/sle_air_mouse_server_adv.c
        ${CMAKE_CURRENT_SOURCE_DIR}/mouse/sle_air_mouse_server/sle_air_mouse_server.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic/vdt_codec.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic/vdt_pdm.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic/amic_voice.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/sle_service/sle_service_ntf.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/common/app_common.c
    )
    set(HEADER_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/amic
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/sle_service
        ${CMAKE_CURRENT_SOURCE_DIR}/../rcu/rcu/common
    )
endif()

if(DEFINED CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
    if(DEFINED CONFIG_AIR_MOUSE_HR_BOARD OR DEFINED CONFIG_AIR_MOUSE_HX_BOARD)
        set(SOURCES_LIST
            ${SOURCES_LIST}
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/common/air_mouse_queue.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/common/air_mouse_timer.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/keyscan/air_mouse_keyscan.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/keyscan/proc_key_hold.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/keyscan/proc_key_event.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/led/air_mouse_led.c
            ${CMAKE_CURRENT_SOURCE_DIR}/mouse/rcu_main.c
        )
    endif()
endif()

set(SOURCES "${SOURCES}" ${SOURCES_LIST} PARENT_SCOPE)
set(PUBLIC_HEADER "${PUBLIC_HEADER}" "${CMAKE_CURRENT_SOURCE_DIR}" ${HEADER_LIST} PARENT_SCOPE)
