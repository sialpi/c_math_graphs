CC=g++
NAMES:=coseno parabola seno tangente
GRID_SRC=grid.cpp
INCLUDE=-I$(ROOT_DIR)/include

.PHONY: all
all:
	@for d in $(NAMES); do \
		$(CC) $$d.cpp $(GRID_SRC) $(INCLUDE) -o $$d; \
	done
