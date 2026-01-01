.PHONY: all clean

all: main

CXX = clang++
CPPFLAGS ?=
CXXFLAGS ?=
override CXXFLAGS += -g -Wmost -Werror

LDFLAGS ?=
LDLIBS ?=

SRCS := $(wildcard *.cpp plugboard/*.cpp rotor/*.cpp)
OBJS := $(SRCS:.cpp=.o)
OBJS_DEBUG := $(SRCS:.cpp=.debug.o)

DEPS := $(OBJS:.o=.d)
DEPS_DEBUG := $(OBJS_DEBUG:.o=.d)

-include $(DEPS) $(DEPS_DEBUG)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

CXXFLAGS_DEBUG ?= -U_FORTIFY_SOURCE -O0

main-debug: $(OBJS_DEBUG)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

%.debug.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(CXXFLAGS_DEBUG) -MMD -MP -c $< -o $@

clean:
	rm -f main main-debug $(OBJS) $(OBJS_DEBUG) $(DEPS) $(DEPS_DEBUG)
