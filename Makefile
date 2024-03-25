CXX = g++  
CXXFLAGS = -Wall
SRCS = main.cpp rock_paper_scissors.cpp agent.cpp entity.cpp
OBJS = $(SRCS:.cpp=.o)  
TARGET = simulater  
  
.PHONY: all clean  
  
all: $(TARGET)  
  
$(TARGET): $(OBJS)  
	$(CXX) $(CXXFLAGS) -o $@ $^  
  
%.o: %.cpp  
	$(CXX) $(CXXFLAGS) -c $< -o $@  
  
clean:  
	rm -f $(OBJS) $(TARGET)