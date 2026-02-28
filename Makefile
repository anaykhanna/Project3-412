CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = loadbalancer
SRC = src/main.cpp src/Utils.cpp src/RequestQueue.cpp src/WebServer.cpp src/LoadBalancer.cpp src/Firewall.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJ)