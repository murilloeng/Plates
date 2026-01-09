#compiler
CXX = g++
WARS = -Wall -Werror
INCS = -I .. -I ../external/cpp/inc -I $(QT_HOME)/include
LIBS = -L $(QT_HOME)/lib -l Qt6Core -l Qt6Gui -l Qt6Widgets -l Qt6OpenGLWidgets -l freetype
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
out = dist/$(mode)/plates.out
lib_canvas = ../Canvas/Canvas/dist/$(mode)/libcanvas.so

#interface files
uif := $(sort $(shell find -path './ui/*.ui'))

#header files
hea := $(sort $(shell find -path './inc/*.hpp'))

#source files
src := $(sort $(shell find -path './src/*.cpp'))

#qt build files
uig := $(subst ./ui/, build/uic/, $(patsubst %.ui, %.hpp, $(uif)))
mog := $(subst ./inc/, build/moc/, $(patsubst %.hpp, %.cpp, $(hea)))

#objects
obj := $(subst ./src/, build/$(mode)/obj/, $(patsubst %.cpp, %.o, $(src)))
obj += $(subst build/moc/, build/$(mode)/moc/, $(patsubst %.cpp, %.o, $(mog)))

#dependencies
dep = $(subst .o,.d, $(obj))

#rules
all : exe

uic : $(uig)

run : exe
	./$(out)

debug : exe
	gdb ./$(out)

canvas :
	+@cd ../Canvas && $(MAKE) -f Makefile m=$m

exe : canvas $(out)
	@echo 'executable build - $(mode): complete!'

$(out) : $(uig) $(mog) $(obj)
	@mkdir -p $(dir $@)
	@$(CXX) -Wl,-rpath,$(QT_HOME)/lib -fopenmp -o $(out) $(obj) $(lib_canvas) $(LIBS)
	@echo 'executable - $(mode): $@'

build/uic/%.hpp : ui/%.ui
	@echo 'uicing($(mode)): $<'
	@mkdir -p $(dir $@) && rm -rf $@
	@$(QT_HOME)/libexec/uic $< -o $@

build/moc/%.cpp: inc/%.hpp
	@echo 'mocing($(mode)): $<'
	@mkdir -p $(dir $@) && rm -rf $@
	@$(QT_HOME)/libexec/moc $< -o $@ -nw

build/$(mode)/obj/%.o : src/%.cpp build/$(mode)/obj/%.d
	@echo 'compiling - $(mode): $<'
	@mkdir -p $(dir $@) && rm -rf $@
	@$(CXX) $(CXXFLAGS) -c $< -o $@

build/$(mode)/moc/%.o : build/moc/%.cpp build/$(mode)/moc/%.d
	@echo 'compiling($(mode)): $<'
	@mkdir -p $(dir $@) && rm -rf $@
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(dep) : ;

-include $(dep)

clean :
	@rm -rf build/$(mode)
	@rm -rf build/uic/$(mode)
	@rm -rf build/moc/$(mode)
	@rm -rf build/dist/$(mode)
	@echo 'clean($(mode)): complete!'


print-% :
	@echo $* = $($*)

.PHONY : all run clean print-%