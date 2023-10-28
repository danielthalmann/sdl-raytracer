
NAME = tracer

SDL2_LIB = $(shell sdl2-config --cflags --libs)

CXXFLAGS = -Werror  -Wfatal-errors
CXXFLAGS += -pedantic
CXXFLAGS += -g

LDFLAGS = $(SDL2_LIB)

SRCS = 	src/main.cpp \
		src/Color.cpp \
		src/Ray.cpp \
		src/Camera.cpp \
		src/shape/Shape.cpp \
		src/shape/Sphere.cpp \
		src/App.cpp 

OBJS = $(SRCS:.cpp=.o)


%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)


all: $(NAME)

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)


run : $(NAME)
	./$(NAME) 

image : clean $(NAME)
	./$(NAME) 
	
# ; convert image.ppm picture.png 

.PHONY: all clean fclean re run leak json
