### COMPILATION ###
CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

### INCLUDES ###
PROJECT = hi_brain 
PROJECT_DIR = ./

SRC_DIR = ./
SRC_FILE = main.cpp
			   
### HEADER FILE ###
# HEADER_DIR = includes

## OBJECT FILE ###
OBJ_DIR = .obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.cpp=.o))

.PHONY= all clean fclean

### RULES ###
all : $(PROJECT)

# COMPILE PROJECT
$(PROJECT) : $(OBJ_SRC) $(OBJ_MANDATORY)
	$(CPP) $(CPPFLAGS) $(OBJ_SRC) -o $(PROJECT)

# COMPILE OBJECT FILE
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -c $< -o $@

# DELETE OBJECT FILE AND EXECUTABLE
fclean : clean
	rm -f $(PROJECT)

# DELETE OBJECT FILE
clean :
	rm -f $(OBJ_DIR)/*.o
	@rm -df $(OBJ_DIR)/

# DELETE EXECUTABLE OBJECT FILE THEN MAKE ALL
re : fclean all
