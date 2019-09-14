src := $(shell find . -name "*.cpp")
obj := $(src:.cpp=.o)
includes := -IC:/Users/Pyros/Desktop/Programming/Libraries/glm -IC:/Users/Pyros/Desktop/Programming/Libraries/glfw-33/include
libs := -LC:\Users\Pyros\Desktop\Programming\Libraries\glfw-33\lib-mingw-w64
CFLAGS := -O3 -Wall $(includes)
LDFLAGS := -lGL -lglfw3

vinegar: $(obj)
	$(CXX) $(includes) -o $@ $^ $(CFLAGS) $(libs) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) vinegar