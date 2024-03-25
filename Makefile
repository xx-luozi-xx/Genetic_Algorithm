CXX = g++  
CXXFLAGS = -Wall -O2
SRCS = main.cpp rock_paper_scissors.cpp agent.cpp entity.cpp luozilib.cpp
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