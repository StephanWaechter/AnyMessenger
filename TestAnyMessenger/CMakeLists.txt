# CMakeList.txt : CMake project for AnyQueue, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (TestAnyMessenger 
	"TestAnyMessenger.cpp"
	"Messages.hpp"
	"Reciver1.hpp"
	"Reciver2.hpp"
)
target_link_libraries(TestAnyMessenger AnyMessenger)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestAnyMessenger PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
