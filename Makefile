CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRCS = main.cpp Corretor.cpp Cliente.cpp Imovel.cpp Agendamento.cpp
OBJS = $(SRCS:.cpp=.o)

imobiliaria: $(SRCS)
	$(CXX) $(CXXFLAGS) -o imobiliaria $(SRCS)

clean:
	rm -f imobiliaria *.o