SOURCE_PATH = src/
OBJ_PATH = build/obj/
DEBUG_PATH = Last-Day-D
RELEASE_PATH = Last-Day
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = /usr/lib
DEPEND_PATH = build/depend
SOURCES = $(shell find $(SOURCE_PATH) -type f -name "*.cpp" -printf '%p ')
#STO = $(OBJ_PATH)$(shell basename -a $(SOURCES))
#TODO prepend objs with OBJ_PATH and also update make depend rules
OBJS = $(SOURCES:.cpp=.o)
CXX = g++
DEBUG = -g
STD = -std=c++14
LDLIBS =  -lboost_filesystem -lboost_system -lSDL
INCFLAGS = -I $(INCLUDE_PATH)
LIBFLAGS = -L $(LIBRARY_PATH)
CXXFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)
LDFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)

.PHONY : depend clean all run

all : $(SOURCES) $(TARGET_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c -MMD $< -o $@

depend : $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $(DEPEND_PATH)

clean :
	$(RM) $(OBJS) $(OBJS:.o=.d) *~ $(TARGET_PATH) $(DEPEND_PATH)

run : $(TARGET_PATH)
	./$(TARGET_PATH)


-include $(DEPEND_PATH)
