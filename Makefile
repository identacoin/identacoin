OUT_FOLDER=bin

ifeq ($(OS),Windows_NT)
    uname_S := Windows
else
    uname_S := $(shell uname -s)
endif

BASENAME=identacoin

ifeq ($(uname_S), Windows)
    OUT_FILE=${OUT_FOLDER}/${BASENAME}.exe
	LIBS := -lws2_32 -lwsock32
endif
ifeq ($(uname_S), Linux)
    OUT_FILE=${OUT_FOLDER}/${BASENAME}
	LIBS := 
endif

SRC_DIR := src
OBJ_DIR := obj
OBJ_DIRS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%, $(wildcard ${SRC_DIR}/*/)) 
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard ${SRC_DIR}/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := 
CPPFLAGS := 
CXXFLAGS := 


build: ${OBJ_DIR} ${OBJ_DIRS} ${OUT_FOLDER} ${OUT_FILE}
	

clean:
	- rm -rf ${OUT_FOLDER}
	- rm -rf ${OBJ_DIR}

test:
	echo ${OBJ_DIRS}
	x=("$(/usr/bin/find ${SRC_DIR} -print)")
	echo $x

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

${OUT_FILE}: $(OBJ_FILES) 
	g++ $(LDFLAGS) -o $@ $^ ${LIBS}

${OUT_FOLDER}:
	mkdir ${OUT_FOLDER}

${OBJ_DIR}:
	mkdir ${OBJ_DIR}	

${OBJ_DIRS}:
	mkdir $@	

run: build
	bin/identacoin.exe Server > serverOut.log &
	bin/identacoin.exe Client > clientOut.log & 