SRC_DIR   := cppFiles
BUILD_DIR := build
SRCS      := server.cpp greeter.cpp register.cpp login.cpp dbLogin.cpp openProject.cpp
OBJS      := $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))
DEPS      := $(OBJS:.o=.d)
TARGET    := server

UNAME := $(shell uname -s)

ifeq ($(UNAME),Darwin)
    CXXFLAGS := -std=c++20 -I$(SRC_DIR) -DASIO_NO_DEPRECATED=0 -I/opt/homebrew/include
    LDFLAGS  := -L/opt/homebrew/lib -L/opt/homebrew/opt/libpq/lib
else
    CXXFLAGS := -std=c++17 -I$(SRC_DIR)
    LDFLAGS  :=
endif

CXXFLAGS += -MMD -MP
LDLIBS   := -lpqxx -lpq -lpthread

# Link step: .o files -> executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# Compile step: one .cpp -> one .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean

-include $(DEPS)