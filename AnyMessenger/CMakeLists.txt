add_library (AnyMessenger INTERFACE "Messenger.hpp" "Reciver.hpp")

target_include_directories(AnyMessenger INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AnyMessenger PROPERTY CXX_STANDARD 20)
endif()