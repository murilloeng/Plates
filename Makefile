#compiler
CXX = g++
WARS = -Wall -Werror
INCS = -I .. -I ../external/cpp/inc
LIBS = -l freetype -l pthread -l GL -l glfw
CXXFLAGS = -std=c++20 -fPIC -pipe -fopenmp -MT $@ -MMD -MP -MF $(subst .o,.d, $@) $(DEFS) $(INCS) $(WARS)

#mode
ifneq ($(m), r)
	mode = debug
	CXXFLAGS += -ggdb3
else
	mode = release
	CXXFLAGS += -Ofast
endif

#ouput
out = dist/$(mode)/plate.out
lib_canvas = ../Canvas/Canvas/dist/$(mode)/libcanvas.so

#sources
src := $(sort $(shell find -path './src/*.cpp'))

#objects
obj = $(sort $(subst ./src/, build/$(mode)/, $(addsuffix .o, $(basename $(src)))))

#dependencies
dep = $(subst .o,.d, $(obj))

#rules
all : exe

run : exe
	./$(out)

debug : exe
	gdb ./$(out)

exe : $(out)
	@echo 'executable build - $(mode): complete!'

$(out) : $(obj)
	@mkdir -p $(dir $@)
	@g++ -fopenmp -o $(out) $(obj) $(lib_canvas) $(LIBS)
	@echo 'executable - $(mode): $@'

build/$(mode)/%.o : src/%.cpp build/$(mode)/%.d
	@echo 'compiling - $(mode): $<'
	@mkdir -p $(dir $@) && rm -rf $@
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(dep) : ;

-include $(dep)

clean :
	@rm -rf dist/$(mode)
	@rm -rf build/$(mode)
	@echo 'clean - $(mode): complete!'

print-% :
	@echo $* = $($*)

.PHONY : all clean print-%