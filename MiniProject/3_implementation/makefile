# Name of the project
PROJECT_NAME = Coronapatients

# Output directory
BUILD = build

# All source code files
SRC = main.c\
src/coronapatients.c\

TEST_SRC = src/coronapatients.c\
test/test.c

TEST_OUTPUT = $(BUILD)/Test_$(PROJECR_NAME).out


# All include folders with header files
INC	= -Iunity\
-Iinc\
-Itest

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test  doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out -lm

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out


	
# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

# Create new build folder if not present
$(BUILD):
	mkdir build
