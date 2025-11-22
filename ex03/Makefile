NAME = bonus

INCLUDES = inc
SRCS = srcs/
CLASS = $(SRCS)class/
SRC = 	$(CLASS)AMateria.cpp \
		$(CLASS)Character.cpp \
		$(CLASS)Cure.cpp \
		$(CLASS)Ice.cpp \
		$(CLASS)MateriaSource.cpp \
		$(SRCS)main.cpp

OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC)))
DEP = $(OBJ:.o=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -std=c++98 -I$(INCLUDES) -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRCS)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLASS)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re