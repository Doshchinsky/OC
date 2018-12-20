LLVM_CONFIG?=/usr/bin/llvm-config

ifndef VERBOSE
QUIET:=@
endif

SRC_DIR?=$(PWD)/src
LDFLAGS+=$(shell $(LLVM_CONFIG) --ldflags)
COMMON_FLAGS=-Wall -Wextra
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags) -fno-rtti
CPPFLAGS+=$(shell $(LLVM_CONFIG) --cppflags) -I$(SRC_DIR)
CLANGLIBS= -Wl,--start-group \
    -lclang -lclangFrontend\
    -lclangDriver -lclangSerialization -lclangParse\
    -lclangSema -lclangAnalysis -lclangEdit\
    -lclangAST -lclangLex -lclangBasic\
    -Wl,--end-group
LLVMLIBS=$(shell $(LLVM_CONFIG) --libs)
SYSTEMLIBS=$(shell $(LLVM_CONFIG) --system-libs)
PROJECT=cmplexer
PROJECT_OBJECTS=lexer.o

default: $(PROJECT) move

%.o : $(SRC_DIR)/%.cpp
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(PROJECT) : $(PROJECT_OBJECTS)
	@echo Linking $@
	$(QUIET)$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(CLANGLIBS) $(LLVMLIBS) $(SYSTEMLIBS)

move:
	mv lexer.o obj/lexer.o
	mv cmplexer bin/cmplexer

.PHONY: clean
clean:
	rm -r -f bin/$(PROJECT)
	rm -r -f obj/$(PROJECT_OBJECTS)
