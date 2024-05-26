# Компилятор и флаги компиляции
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Директории
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Файлы
TARGET = $(BINDIR)/b
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# SFML библиотеки
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Правило по умолчанию
all: $(TARGET)

# Создание целевого файла
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Создание объектных файлов
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Правило для очистки
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Зависимости
$(OBJDIR)/main.o: $(INCDIR)/Snake.h $(INCDIR)/Food.h $(INCDIR)/Constants.h
$(OBJDIR)/Snake.o: $(INCDIR)/Snake.h $(INCDIR)/Constants.h
$(OBJDIR)/Food.o: $(INCDIR)/Food.h $(INCDIR)/Constants.h
$(OBJDIR)/Constants.o: $(INCDIR)/Constants.h

.PHONY: all clean