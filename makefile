SOURCE_PATH = src/
BUILD_PATH = build/
OBJ_PATH = $(BUILD_PATH)obj/
DEBUG_PATH = Last-Day-D
RELEASE_PATH = Last-Day
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = /usr/lib
SOURCES = $(shell find $(SOURCE_PATH) -type f -name "*.cpp" -printf '%p ')
HEADERS = $(shell find $(SOURCE_PATH) -type f -name "*.hpp" -printf '%p ')
OBJS = $(addprefix $(OBJ_PATH),$(patsubst %.cpp,%.o,$(shell find $(SOURCE_PATH) -type f -name "*.cpp" -exec basename {} \;)))
CXX = g++
DEBUG = -g -O0
STD = -std=c++14
LDLIBS =  -lboost_filesystem -lboost_system -lSDL
INCFLAGS = -I $(INCLUDE_PATH)
LIBFLAGS = -L $(LIBRARY_PATH)
CXXFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)
LDFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)

.PHONY : clean run

$(TARGET_PATH) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

.SECONDEXPANSION:
$(OBJ_PATH)%.o : $$(shell find $(SOURCE_PATH) -type f -name %.cpp)
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	$(CXX) -MM $(CXXFLAGS) $< > $(BUILD_PATH)$*.d
	@sed -i '1s/^/build\/obj\//' $(BUILD_PATH)$*.d

clean :
	$(RM) -r $(BUILD_PATH) *~ bin $(TARGET_PATH)

run : $(TARGET_PATH)
	./$(TARGET_PATH)

-include $(shell find $(BUILD_PATH) -type f -name "*.d" -printf '%p ')
