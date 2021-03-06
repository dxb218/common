# 目标文件名，输入任意你想要的执行文件名
TARGET  := test

# 编译参数
CC      := gcc
CXX     := g++
LIBS+=-lpthread
LDFLAGS:= 
DEFINES:=
INCLUDE:= -I.
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
 
 
SOURCE_DIR1 := .
# SOURCE_DIR2 := .

################################# Do Not Change ##############################

#源文件，自动找所有.c和.cpp文件
SOURCE  := $(wildcard $(SOURCE_DIR1)/*.c) $(wildcard $(SOURCE_DIR1)/*.cpp)
            # $(wildcard $(SOURCE_DIR2)/*.c) $(wildcard $(SOURCE_DIR2)/*.cpp)

#将目标定义为同名.o文件
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

all : $(TARGET)

objs : $(OBJS)

clean :
	rm -rf $(TARGET) $(OBJS)

rebuild: clean all

$(TARGET) : $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)