# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jo/Adaptive-AUTOSAR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jo/Adaptive-AUTOSAR

# Include any dependencies generated for this target.
include _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o: _deps/async-bsd-socket-lib-src/src/communicator.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/communicator.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/communicator.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/communicator.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o: _deps/async-bsd-socket-lib-src/src/network_socket.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/network_socket.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/network_socket.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/network_socket.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o: _deps/async-bsd-socket-lib-src/src/poller.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/poller.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/poller.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/poller.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o: _deps/async-bsd-socket-lib-src/src/tcp_client.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_client.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_client.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_client.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o: _deps/async-bsd-socket-lib-src/src/tcp_listener.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_listener.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_listener.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/tcp_listener.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o: _deps/async-bsd-socket-lib-src/src/udp_client.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/udp_client.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/udp_client.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/udp_client.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o: _deps/async-bsd-socket-lib-src/src/fifo_sender.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_sender.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_sender.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_sender.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.s

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/flags.make
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o: _deps/async-bsd-socket-lib-src/src/fifo_receiver.cpp
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o -MF CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o.d -o CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o -c /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_receiver.cpp

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.i"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_receiver.cpp > CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.i

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.s"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src/src/fifo_receiver.cpp -o CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.s

# Object files for target async_bsd_socket_lib
async_bsd_socket_lib_OBJECTS = \
"CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o" \
"CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o"

# External object files for target async_bsd_socket_lib
async_bsd_socket_lib_EXTERNAL_OBJECTS =

_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/communicator.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/network_socket.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/poller.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_client.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/tcp_listener.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/udp_client.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_sender.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/src/fifo_receiver.cpp.o
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/build.make
_deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a: _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jo/Adaptive-AUTOSAR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libasync_bsd_socket_lib.a"
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && $(CMAKE_COMMAND) -P CMakeFiles/async_bsd_socket_lib.dir/cmake_clean_target.cmake
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/async_bsd_socket_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/build: _deps/async-bsd-socket-lib-build/libasync_bsd_socket_lib.a
.PHONY : _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/build

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/clean:
	cd /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build && $(CMAKE_COMMAND) -P CMakeFiles/async_bsd_socket_lib.dir/cmake_clean.cmake
.PHONY : _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/clean

_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/depend:
	cd /home/jo/Adaptive-AUTOSAR && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jo/Adaptive-AUTOSAR /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-src /home/jo/Adaptive-AUTOSAR /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build /home/jo/Adaptive-AUTOSAR/_deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/async-bsd-socket-lib-build/CMakeFiles/async_bsd_socket_lib.dir/depend

