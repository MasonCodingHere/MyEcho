set (CLIENT_SRC_LIST
		./MyClient.cpp
		./client.cpp)
set (SERVER_SRC_LIST
		./MyServer.cpp
		./server.cpp)
include_directories (../include)

if (CLIENT)
	add_executable (client ${CLIENT_SRC_LIST})
else()
	add_executable (server ${SERVER_SRC_LIST})
endif()

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
