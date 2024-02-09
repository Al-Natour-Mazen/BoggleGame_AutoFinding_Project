# A simple makefile by Mazen
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -Ofast
SRCDIR = src
BUILDDIR = src/build
TARGET = boggle

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo ">> Linking objects to create executable: $@"
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo ">> Executable '$(TARGET)' created successfully."

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@echo "Compiling: $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILDDIR) $(TARGET)
	@rm -f possibleWords.txt
	@echo "Cleanup complete." 
