OUT_FOLDER=bin

ifeq ($(OS),Windows_NT)
    uname_S := Windows
else
    uname_S := $(shell uname -s)
endif

BASENAME=identacoin

ifeq ($(uname_S), Windows)
    OUT_FILE=${OUT_FOLDER}/${BASENAME}.exe
	LIBS := -lws2_32 -lwsock32 -lcryptopp -lssl
	LDFLAGS := -static
endif
ifeq ($(uname_S), Linux)
    OUT_FILE=${OUT_FOLDER}/${BASENAME}
	LIBS := -lcryptopp -pthread 
	LDFLAGS := -static
endif

SRC_DIR := src
OBJ_DIR := obj
OBJ_DIRS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%, $(wildcard ${SRC_DIR}/*/)) 
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard ${SRC_DIR}/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
BASE_VERSION_NUM := 0.1
VERSION := ${BASE_VERSION_NUM}.$(shell git show --oneline -s --format="%h %d")
BUILD_DATE := $(shell date "+%Y/%m/%d %H:%M:%S")
LDEXT := 
CPPFLAGS := -DBUILDDATE="\"${BUILD_DATE}\"" -DVERSION="\"${VERSION}\""
CXXFLAGS := 
LOGS := logs

build: ${OBJ_DIR} ${OBJ_DIRS} ${OUT_FOLDER} ${OUT_FILE}
	
clean:
	- rm -rf ${OUT_FOLDER}
	- rm -rf ${OBJ_DIR}
	- rm -rf ${LOGS}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

${OUT_FILE}: $(OBJ_FILES) 
	g++ $(LDFLAGS) -o $@ $^ ${LIBS} ${LDEXT}

${OUT_FOLDER}:
	mkdir ${OUT_FOLDER}

${OBJ_DIR}:
	mkdir ${OBJ_DIR}	

${OBJ_DIRS}:
	mkdir $@	

${LOGS}:
	mkdir $@	

run: ${LOGS} build
	bin/identacoin.exe Server > ${LOGS}/serverOut.log &
	bin/identacoin.exe Client > ${LOGS}/clientOut.log & 

runTest: ${LOGS} build
	bin/identacoin.exe Test
	