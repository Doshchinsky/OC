LLVM_CONFIG?=/usr/bin/llvm-config

ifndef VERBOSE
QUIET:=@
endif

SRC_DIR?=$(PWD)/src
LDFLAGS+=$(shell $(LLVM_CONFIG) --ldflags)
COMMON_FLAGS=-Wall -Wextra
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags) -fno-rtti
CPPFLAGS+=$(shell $(LLVM_CONFIG) --cppflags) -I$(SRC_DIR)
LLVMLIBS=$(shell $(LLVM_CONFIG) --libs bitreader support)
SYSTEMLIBS=$(shell $(LLVM_CONFIG) --system-libs)

HELLO=release
HELLO_OBJECTS=release.o

default: $(HELLO) move

$(HELLO_OBJECTS): $(SRC_DIR)/release.cpp
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(HELLO): $(HELLO_OBJECTS)
	@echo Linking $@
	$(QUIET)$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(LLVMLIBS) $(SYSTEMLIBS)

move:
	mv release.o obj/release.o
	mv release bin/release

.PHONY: clean exec
clean:
	rm -r -f bin/$(HELLO)
	rm -r -f obj/$(HELLO_OBJECTS)
